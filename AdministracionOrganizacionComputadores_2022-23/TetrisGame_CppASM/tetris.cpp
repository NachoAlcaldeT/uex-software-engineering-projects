/***************************************************************************
 *   Copyright (C) 2022 by pilar                                           *
 *   pilarb@unex.es                                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "tetris.h"

//#define WITH_SSE

void tetris::vaciaContenedor(char * container, int w, int h)
{
#ifndef WITH_SSE
    asm volatile(

        "mov %0, %%rsi;" //Se refiere al primer parametro (char *contanier)
        "mov %1, %%eax;"//Segundo parametro (int w)
        "mov %%eax, %%ebx;"
        "sub $2, %%ebx;"
        "mov $0, %%rcx;"
        "mov %2, %%ecx;"//Tercer parametro (int h)
        "BVaciarF:"
            "mov $0, %%edi;"
            "BVaciarC:"
                "cmp $2, %%edi;"
                "jl sigVaciar;"
                "cmp %%ebx, %%edi;"
                "jge sigVaciar;"
                "movb $0, (%%rsi);"
            "sigVaciar:"
                "inc %%rsi;"
                "inc %%edi;"
                "cmp %%eax, %%edi;"
                "jl BVaciarC;"
            "loop BVaciarF;"

        :
        : "m" (container), "m" (w), "m" (h)
        : "%rax", "%rbx", "%rcx", "%rsi", "%rdi", "memory" // Relacion de los registros empleados deben ser registrados en memory

    );
#else
    asm volatile(
        // Por simplificación, asumimos w=16.
        // Dicho valor es el utilizado como anchura en la definición de "container"

        "mov %0, %%rsi;"
        "mov $0, %%rcx;"
        "mov %2, %%ecx;"

        "pxor %%xmm0, %%xmm0;"
        "mov $0xFFFF0000, %%eax;"
        "pinsrd $3, %%eax, %%xmm0;"
        "mov $0x0000FFFF, %%eax;"
        "pinsrd $0, %%eax, %%xmm0;"

        "BVaciarF:"
            "movdqu (%%rsi), %%xmm1;"
            "pand %%xmm0, %%xmm1;"
            "movdqu %%xmm1, (%%rsi);"

            "add $16, %%rsi;"
            "loop BVaciarF;"
        :
        : "m" (container), "m" (w), "m" (h)
        : "%rax","%rcx","%rsi","%xmm0","%xmm1","memory"

    );

#endif


}


void tetris::borraPieza(char * container, int w, char figure[4][4], int c, int f)
{

#ifndef WITH_SSE
    //rsi = dirContainer
    //r8 = dirFigure
    //rax = int fAct
    //r9 = df
    //r10 = posCelda
    //r11 = c
    //r12 = dc

    asm volatile(
                ";"
                        //rdi= dirContainer
                        //rsi= dirFigure
                        //rax=fAct
                            //rcx=df

                 "mov %0, %%rdi;"
                "mov %2, %%rsi;"
                "mov %4, %%eax;"
                "movsx %%eax, %%rax;"
                "mov $0, %%ecx;"
                "movsx %%ecx, %%rcx;"
                "jmp condicionForBorrarPieza;"
                    "cuerpoForBorrarPieza:"
                "mov %1, %%ebx;"
                "movsx %%ebx, %%rbx;"
                "imul %%rax, %%rbx;"
                "mov %3, %%edx;"
                "movsx %%edx, %%rdx;"
                "add %%rdx, %%rbx;"//Poscelda
                        "xor %%r8,%%r8;"
                        "jmp condicionFor2BorrarPieza;"
                            "cuerpoFor2BorrarPieza:"
                                "movb (%%rsi), %%dl;"
                                "cmpb $0, %%dl;"
                                "je continuarIfBorrarPieza;"
                                "movb $0, (%%rdi, %%rbx);"
                        "continuarIfBorrarPieza:"
                        "inc %%rbx;"
                        "inc %%rsi;"

                        "inc %%r8;"
                        "condicionFor2BorrarPieza:"
                        "cmp $4, %%r8;"
                        "jl cuerpoFor2BorrarPieza;"
                 "inc %%rax;"
                "inc %%rcx;"
                "condicionForBorrarPieza:"
                "cmp $4, %%rcx;"
                "jl cuerpoForBorrarPieza;"
                :
                : "m" (container), "m" (w), "m" (figure), "m" (c), "m" (f)
                : "%rax","%rsi","%rdi","%rbx","%rdx","%rcx","%r8","memory"

            );
#else
    asm volatile(
        ";"

        :
        : "m" (container), "m" (w), "m" (figure), "m" (c), "m" (f)
        : "memory"

    );


#endif



}

bool tetris::huecoLibre(char * container, int w, char figure[4][4], int c, int f)
{
    bool hayHueco = true;

#ifndef WITH_SSE
    asm volatile(
                ";"
                //rdi= dirContainer
                //rsi= dirFigure
                //r9=fAct
                //rcx=df
                //al=hayHueco

                "mov %0, %%al;" //hayHueco= true;
                "mov $1, %%al;"
                "mov %1, %%rdi;"
                "mov %3, %%rsi;"
                "xor %%r9, %%r9;"
                "mov %5, %%r9d;"
                "movsx %%r9d, %%r9;"
                "xor %%rcx, %%rcx;"
                "jmp condicionForHayHueco;"
                "cuerpoForHayHueco:"
                "mov %2, %%ebx;"
                "movsx %%ebx, %%rbx;"
                "imul %%r9, %%rbx;"
                "mov %4, %%edx;"
                "movsx %%edx, %%rdx;"
                "add %%rdx, %%rbx;"  //Poscelda
                        "xor %%r8,%%r8;"
                        "jmp condicionFor2HayHueco;"
                            "cuerpoFor2HayHueco:"
                                "mov (%%rsi), %%dl;"
                                "cmp $0, %%dl;"
                                "je continuarIfHayHueco;"
                                "mov (%%rdi, %%rbx), %%dl;"
                                "cmp $0, %%dl;"
                                "je continuarIfHayHueco;"
                                "mov $0, %%al;"
                        "continuarIfHayHueco:"
                        "inc %%rbx;"
                        "inc %%rsi;"

                        "inc %%r8;"
                        "condicionFor2HayHueco:"
                        "cmp $4, %%r8;"
                        "jge terminar2;"
                        "cmp $1, %%al;"
                        "jne terminar2;"
                        "jmp cuerpoFor2HayHueco;"

                "terminar2:"
                "inc %%r9;"
                "inc %%rcx;"
                "condicionForHayHueco:"
                "cmp $4, %%rcx;"
                "jge terminar;"
                "cmp $1, %%al;"
                 "jne terminar;"
                 "jmp cuerpoForHayHueco;"
                        "terminar:"
               "mov %%al,%0;"
                : "=m" (hayHueco)
                : "m" (container), "m" (w), "m" (figure), "m" (c), "m" (f)
                : "%rax","%rsi","%rdi","%rbx","%rdx","%rcx","%r8","%r9","memory"

            );


#endif

    return hayHueco;
}

void tetris::insertaPieza(char * container, int w, char figure[4][4], int c, int f)
{


#ifndef WITH_SSE
    asm volatile(
        ";"
                //rdi= dirContainer
                //rsi= dirFigure
                //rax=fAct
                    //rcx=df

         "mov %0, %%rdi;"
        "mov %2, %%rsi;"
        "mov %4, %%eax;"
        "movsx %%eax, %%rax;"
        "mov $0, %%ecx;"
        "movsx %%ecx, %%rcx;"
        "jmp condicionForInsertarPieza;"
            "cuerpoForInsertarPieza:"
        "mov %1, %%ebx;"
        "movsx %%ebx, %%rbx;"
        "imul %%rax, %%rbx;"
        "mov %3, %%edx;"
        "movsx %%edx, %%rdx;"
        "add %%rdx, %%rbx;"//Poscelda
                "xor %%r8,%%r8;"
                "jmp condicionFor2InsertarPieza;"
                    "cuerpoFor2InsertarPieza:"
                        "movb (%%rsi), %%dl;"
                        "cmpb $0, %%dl;"
                        "je continuarIfInsertarPieza;"
                        "movb %%dl, (%%rdi, %%rbx);"
                "continuarIfInsertarPieza:"
                "inc %%rbx;"
                "inc %%rsi;"

                "inc %%r8;"
                "condicionFor2InsertarPieza:"
                "cmp $4, %%r8;"
                "jl cuerpoFor2InsertarPieza;"
         "inc %%rax;"
        "inc %%rcx;"
        "condicionForInsertarPieza:"
        "cmp $4, %%rcx;"
        "jl cuerpoForInsertarPieza;"
        :
        : "m" (container), "m" (w), "m" (figure), "m" (c), "m" (f)
        : "%rax","%rsi","%rdi","%rbx","%rdx","%rcx","%r8","memory"

    );

#else

    asm volatile(
        ";"

        :
        : "m" (container), "m" (w), "m" (figure), "m" (c), "m" (f)
        : "memory"

    );

#endif


}

int tetris::borraFilas(char * container, int w, int h)
{
    int nFilas = 0;
    //dirContainer = edi
    //r8 = fAct
    //r9= celdasOcupadas
    //r10 = posCelda
    //r11 = c
    //r12 = filaVacia
    //r13 = f
    //r14 = posBorra
    //r15 = posEncima
    //rax = celdasNoVacias

    asm volatile(
        ";"
        "movl $0, %0;"
               "mov %1, %%rdi;"
               "mov $0, %%r8;"
               "mov %3, %%r8d;"
               "dec %%r8d;"

               "while:"
                   "mov $0, %%r9;"
                   "mov %2, %%r10d;"
                   "imul %%r8d, %%r10d;"
                   "add $2, %%r10d;"

                   "mov $2, %%r11;"
                   "jmp condicionFor1BorrarFilas;"
                       "cuerpoFor1BorrarFilas:"
                       "cmpb $0, (%%rdi, %%r10);"
                       "je continuarFor1BorrarFilas;"
                           "inc %%r9d;"
                       "continuarFor1BorrarFilas:"
                       "inc %%r10d;"
                       "inc %%r11d;"
                       "condicionFor1BorrarFilas:"
                       "mov %2, %%r12d;"
                       "sub $2, %%r12d;"
                       "cmp %%r12d, %%r11d;"
                       "jl cuerpoFor1BorrarFilas;"

                       "mov %2, %%r11d;"
                       "sub $4, %%r11d;"
                       "cmp %%r11d, %%r9d;"
                       "jne terminarIf1BorrarFilas;"

                       "incl %0;"
                       "mov $0, %%r12;"
                       "mov $0, %%r13;"
                       "mov %%r8d, %%r13d;"
                       "jmp condicionFor2BorrarFilas;"
                       "cuerpoFor2BorrarFilas:"
                           "mov %2, %%eax;"
                           "mov $0, %%r14;"
                           "mov %%r13d, %%r14d;"
                           "mul %%r14d;"
                           "mov %%rax, %%r14;"
                           "add $2, %%r14;"

                           "mov %2, %%eax;"
                           "mov $0, %%r15;"
                           "mov %%r13d, %%r15d;"
                           "dec %%r15d;"
                           "mul %%r15d;"
                           "mov %%rax, %%r15;"
                           "add $2, %%r15;"

                           "mov $0, %%rax;"
                           "mov $2, %%rcx;"
                           "jmp condicionFor3BorrarFilas;"
                            "cuerpoFor3BorrarFilas:"
                               "cmpb $0, (%%rdi, %%r15);"
                               "je continuarFor3BorrarFilas;"
                               "dec %%rax;"
                               "continuarFor3BorrarFilas:"
                               "movb (%%rdi, %%r15), %%dl;"
                               "movb %%dl, (%%rdi, %%r14);"
                               "inc %%r15;"
                               "inc %%r14;"

                           "inc %%ecx;"
                           "condicionFor3BorrarFilas:"
                           "mov %2, %%ebx;"
                           "sub $2, %%ebx;"
                           "cmp %%ebx, %%ecx;"
                           "jl cuerpoFor3BorrarFilas;"

                           "cmp $0, %%rax;"
                           "jne continuarFor2BorrarFilas;"
                           "mov $1, %%r12;"
                           "continuarFor2BorrarFilas:"


                   "dec %%r13d;"
                   "condicionFor2BorrarFilas:"
                   "cmp $0, %%r13d;"
                   "jle terminarFor2BorrarFilas;"
                   "cmp $0, %%r12;"
                   "je cuerpoFor2BorrarFilas;"

                   "terminarFor2BorrarFilas:"
                   "cmp $0, %%r12;"
                   "jne continuarFor1BorrarFilas2;"
                       "mov %2, %%eax;"
                       "mov $0, %%r14;"
                       "mov %%r13d, %%r14d;"
                       "mul %%r14d;"
                       "mov %%rax, %%r14;"
                       "add $2, %%r14;"

                       "mov $2, %%rcx;"
                       "jmp condicionFor4BorrarFilas;"
                           "cuerpoFor4BorrarFilas:"
                           "movb $0, (%%rdi, %%r14);"
                           "inc %%r14;"
                       "inc %%ecx;"
                       "condicionFor4BorrarFilas:"
                       "mov %2, %%ebx;"
                       "sub $2, %%ebx;"
                       "cmp %%ebx, %%ecx;"
                       "jl cuerpoFor4BorrarFilas;"

                   "continuarFor1BorrarFilas2:"
                   "inc %%r8d;"

                   "terminarIf1BorrarFilas:"
                   "dec %%r8d;"
               "cmp $0, %%r9d;"
               "jle terminarBorrarFilas;"
               "cmp $0, %%r8d;"
               "jge while;"

               "terminarBorrarFilas:"

               : "=m" (nFilas)
               : "m" (container), "m" (w), "m" (h)
               : "%rax","%rbx", "%rcx","%rdx","%rdi","%r8","%r9","%r10","%r11","%r12","%r13","%r14","%r15","memory"
    );

    return nFilas;
}

void tetris::annadeFila(char * container, int w, int h, char * row)
{
    asm volatile(
        ";"


        "mov %0,%%rdi;"
        "xor %%rax,%%rax;"      //rax=posCelda
        "xor %%rbx,%%rbx;"
        "mov %1,%%ebx;"         //rbx=posCopia
        "xor %%rcx,%%rcx;"
        "jmp condicion1anadir;"

          "cuerpoCondicion1anadir:"
        "xor %%r8,%%r8;"   //r8=c
        "jmp condicion2anadir;"

           "cuerpoCondicion2anadir:"
        "mov (%%rdi,%%rbx),%%dl;"
        "mov %%dl,(%%rdi,%%rax);"
        "inc %%rbx;"
        "inc %%rax;"

        "inc %%r8d;"
        "condicion2anadir:"
        "xor %%r9, %%r9;"
        "mov %1,%%r9d;"
        "cmp %%r9d,%%r8d;"
        "jl cuerpoCondicion2anadir;"

        "inc %%ecx;"
        "condicion1anadir:"
        "mov %2,%%edx;"
        "dec %%edx;"
        "cmp %%edx,%%ecx;"
        "jl cuerpoCondicion1anadir;"

        "mov %3,%%r9;"
        "xor %%rcx,%%rcx;"
        "jmp condicion3;"
        "cuerpo3:"
        "mov (%%r9),%%dl;"
        "mov %%dl,(%%rdi,%%rax);"
        "inc %%rax;"
        "inc %%r9;"

        "inc %%ecx;"
        "condicion3:"
        "xor %%r8,%%r8;"
        "mov %1,%%r8d;"
        "cmp %%r8d,%%ecx;"
        "jl cuerpo3;"

        :
        : "m" (container), "m" (w), "m" (h), "m" (row)
        : "%rax","%rbx","%rcx","%rdx","%rdi","%r8","%r9","memory"

    );

}
