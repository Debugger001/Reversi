//
//  main.c
//  Reversichess
//
//  Created by LC on 2016/11/11.
//  Copyright © 2016年 LC. All rights reserved.
//

#include <stdio.h>

#define SIZE 8

int isvalid = 0;

int ispass = 0;

int iswin = 2;

int isdoublepass = 0;

int Flip = 0;

int isgarbage = 0;

void ChessBoard(int coordinates[], int isuser[])
{
    //print the first row: 'a' to 'h'
    printf(" ");
    for (int ii =0; ii <= SIZE-1; ii++)
    {
        printf("   %c",'a'+ii);
    }
    printf("\n");
    //print the second row
    printf("  ");
    for (int ii = 0; ii <= SIZE-1; ii++)
    {
        printf("+---");
    }
    printf("+\n");
    //print the next 8 rows
    for (int i = 0; i <= SIZE-1; i++)
    {
        if (i <= 8)
            printf(" %c",'1'+i);
        else
        {
            printf("%d",i+1);
        }
        int ii = 0;
        for (ii = 0; ii <= SIZE - 1; ii++)
        {
            if (coordinates[i*SIZE+ii] == 1)
            {
                if (isuser[i*SIZE+ii] == 1)
                    printf("| O ");
                else if (isuser[i*SIZE+ii]==0)
                    printf("| X ");
            }
            else
            {
                    printf("|   ");
            }
        }
        printf("|");
        printf("\n ");
        printf(" ");
        for (int iii = 0; iii <= SIZE - 1; iii++)
        {
            printf("+---");
        }
        printf("+");
        printf("\n");
    }
    printf("\n");
}

void ChessRule(int umrow, int umcolomn, int coordinates[], int isuser[], int*userorcomp)
{
    Flip = 0;
    isvalid = 0;
    int compos = SIZE*SIZE;
    
    //check the upper vertical line
    if (umrow > 2)
    {
        for (int ii = umrow - 3; ii >= 0; ii--)
        {
            if (coordinates[ii * SIZE + umcolomn - 1] == 1 && isuser[ii * SIZE + umcolomn - 1] == *userorcomp)
            {
                compos = ii;
                break;
            }
        }
        int iii;
        for (iii = umrow - 2; iii > compos; iii--)
        {
            if (coordinates[iii*SIZE+umcolomn-1]==1 && isuser[iii*SIZE+umcolomn-1]==1-*userorcomp)
            {
                continue;
            }
            else
                break;
        }
        if (iii == compos)
        {
            isvalid = isvalid + 1;
            for (int i = umrow-2; i > compos; i--)
            {
                isuser[i*SIZE+umcolomn-1]=*userorcomp;
                Flip = Flip + 1;
            }
        }
        compos = SIZE*SIZE;
    }
    
    //check the lower vertical line
    if (umrow <= SIZE - 2)
    {
        for (int ii = umrow+1; ii < SIZE -1; ii++)
        {
            if (coordinates[ii * SIZE + umcolomn - 1] == 1 && isuser[ii * SIZE + umcolomn - 1] == *userorcomp)
            {
                compos = ii;
                break;
            }
         }
        int iii;
        for (iii = umrow; iii < compos; iii++)
        {
            if (coordinates[iii*SIZE+umcolomn-1]==1 && isuser[iii*SIZE+umcolomn-1]==1-*userorcomp)
            {
                continue;
            }
            else
                break;
        }
        if (iii == compos)
        {
            isvalid = isvalid + 1;
            for (int i = umrow; i < compos; i++)
            {
                isuser[i*SIZE+umcolomn-1]=*userorcomp;
                Flip = Flip + 1;
            }
        }
        compos = SIZE*SIZE;
    }
    
    //check the left horizontal line
    if (umcolomn > 2)
    {
        for (int ii = umcolomn-2; ii > 0; ii--)
        {
            if (coordinates[umrow * SIZE + ii - 1-SIZE] == 1 && isuser[umrow * SIZE + ii - 1-SIZE] == *userorcomp)
            {
                compos = ii;
                break;
            }
        }
        int iii;
        for (iii = umcolomn-1; iii > compos; iii--)
        {
            if (coordinates[umrow*SIZE+iii-1-SIZE]==1 && isuser[umrow*SIZE+iii-1-SIZE]==1-*userorcomp)
            {
                continue;
            }
            else
                break;
        }
        if (iii == compos)
        {
            isvalid = isvalid + 1;
            for (int i = umcolomn-1; i > compos; i--)
            {
                isuser[umrow*SIZE+i-1-SIZE]=*userorcomp;
                Flip = Flip + 1;
            }
        }
        compos = SIZE*SIZE;
    }
    
    //check the right horizontal line
    if (umcolomn <= SIZE - 2)
    {
        for (int ii = umcolomn + 2; ii <= SIZE; ii++)
        {
            if (coordinates[umrow * SIZE + ii - 1-SIZE] == 1 && isuser[umrow * SIZE + ii - 1-SIZE] == *userorcomp)
            {
                compos = ii;
                break;
            }
        }
        int iii;
        for (iii = umcolomn+1; iii < compos; iii++)
        {
            if (coordinates[umrow*SIZE+iii-1-SIZE]==1 && isuser[umrow*SIZE+iii-1-SIZE]==1-*userorcomp)
            {
                continue;
            }
            else
                break;
        }
        if (iii == compos)
        {
            isvalid = isvalid + 1;
            for (int i = umcolomn+1; i < compos; i++)
            {
                isuser[umrow*SIZE+i-1-SIZE]=*userorcomp;
                Flip = Flip + 1;
            }
        }
        compos = SIZE*SIZE;
    }
    
    //check the upper-right diagonal
    if (umrow > 2 && umcolomn <= SIZE - 2)
    {
        int times;
        if (umrow - 1>= (SIZE-umcolomn))
        {
            times = (SIZE-umcolomn);
        }
        else
            times = umrow - 1;
        for (int i = 2; i <= times; i++)
        {
            if (coordinates[(umrow-1-i)*SIZE+umcolomn-1+i]==1 && isuser[(umrow-1-i)*SIZE+umcolomn-1+i]==*userorcomp)
            {
                compos = i;
                break;
            }
        }
        int ii;
        for (ii = 1; ii < compos; ii++)
        {
            if (coordinates[(umrow-1-ii)*SIZE+umcolomn-1+ii]==1 && isuser[(umrow-1-ii)*SIZE+umcolomn-1+ii]==1-*userorcomp)
            {
                continue;
            }
            else
                break;
        }
        if (ii == compos)
        {
            isvalid = isvalid + 1;
            for (int iii = 1; iii < compos; iii++)
            {
                isuser[(umrow-1-iii)*SIZE+umcolomn-1+iii] = *userorcomp;
                Flip = Flip + 1;
            }
        }
        compos = SIZE*SIZE;
    }
    
    //check the upper-left diagonal
    if (umrow > 2 && umcolomn > 2)
    {
        int times;
        if (umrow >= umcolomn)
        {
            times = umcolomn - 1;
        }
        else
            times = umrow - 1;
        for (int i = 2; i <= times; i++)
        {
            if (coordinates[(umrow-1-i)*SIZE+umcolomn-1-i]==1 && isuser[(umrow-1-i)*SIZE+umcolomn-1-i]==*userorcomp)
            {
                compos = i;
                break;
            }
        }
        int ii;
        for (ii = 1; ii < compos; ii++)
        {
            if (coordinates[(umrow-1-ii)*SIZE+umcolomn-1-ii]==1 && isuser[(umrow-1-ii)*SIZE+umcolomn-1-ii]==1-*userorcomp)
            {
                continue;
            }
            else
                break;
        }
        if (ii == compos)
        {
            isvalid = isvalid + 1;
            for (int iii = 1; iii < compos; iii++)
            {
                isuser[(umrow-1-iii)*SIZE+umcolomn-1-iii] = *userorcomp;
                Flip = Flip + 1;
            }
        }
        compos = SIZE*SIZE;
    }
    
    //check the lower-right diagonal
    if (umrow < SIZE - 2 && umcolomn < SIZE - 2)
    {
        int times;
        if ((SIZE-umrow) >= (SIZE-umcolomn))
        {
            times = (SIZE-umcolomn);
        }
        else
            times = (SIZE-umrow);
        for (int i = 2; i <= times; i++)
        {
            if (coordinates[(umrow-1+i)*SIZE+umcolomn-1+i]==1 && isuser[(umrow-1+i)*SIZE+umcolomn-1+i]==*userorcomp)
            {
                compos = i;
                break;
            }
        }
        int ii;
        for (ii = 1; ii < compos; ii++)
        {
            if (coordinates[(umrow-1+ii)*SIZE+umcolomn-1+ii]==1 && isuser[(umrow-1+ii)*SIZE+umcolomn-1+ii]==1-*userorcomp)
            {
                continue;
            }
            else
                break;
        }
        if (ii == compos)
        {
            isvalid = isvalid + 1;
            for (int iii = 1; iii < compos; iii++)
            {
                isuser[(umrow-1+iii)*SIZE+umcolomn-1+iii] = *userorcomp;
                Flip = Flip + 1;
            }
        }
        compos = SIZE*SIZE;
    }
    
    //check the lower-left diagonal
    if (umrow < SIZE - 2 && umcolomn > 2)
    {
        int times;
        if ((SIZE-umrow) >= umcolomn)
        {
            times = umcolomn - 1;
        }
        else
            times = (SIZE-umrow);
        for (int i = 2; i <= times; i++)
        {
            if (coordinates[(umrow-1+i)*SIZE+umcolomn-1-i]==1 && isuser[(umrow-1+i)*SIZE+umcolomn-1-i]==*userorcomp)
            {
                compos = i;
                break;
            }
        }
        int ii;
        for (ii = 1; ii < compos; ii++)
        {
            if (coordinates[(umrow-1+ii)*SIZE+umcolomn-1-ii]==1 && isuser[(umrow-1+ii)*SIZE+umcolomn-1-ii]==1-*userorcomp)
            {
                continue;
            }
            else
                break;
        }
        if (ii == compos)
        {
            isvalid = isvalid + 1;
            for (int iii = 1; iii < compos; iii++)
            {
                isuser[(umrow-1+iii)*SIZE+umcolomn-1-iii] = *userorcomp;
                Flip = Flip + 1;
            }
        }
        compos = SIZE*SIZE;
    }
}

void UserMove(char usermove[], int coordinates[], int isuser[], int*userorcomp)
{
    int umrow, umcolomn;
    if (usermove[0] > '9' || usermove[0] < '0')
    {
        isvalid = 0;
    }
    if (usermove[1] >= '0' && usermove[1] <= '9')
    {
        if (usermove[2] > 'z' || usermove[2] < 'a')
            isvalid = 0;
        else
        {
            umrow = (usermove[0] - '0') * 10 + usermove[1] - '0';
            umcolomn = usermove[2] - 'a' + 1;
        }
    }
    else
    {
        umrow = usermove[0] - '0';
        umcolomn = usermove[1] - 'a' + 1;
    }
    if (coordinates[SIZE*umrow+umcolomn-1-SIZE] == 1)
    {
        isvalid = 0;
    }
    else
    {
        coordinates[SIZE*umrow+umcolomn-1-SIZE] = 1;
        isuser[SIZE*umrow+umcolomn-1-SIZE] = *userorcomp;
        ChessRule(umrow,umcolomn,coordinates,isuser,userorcomp);
    }
}

void isValid(int pos,int coordinates[],int isuser[],int *userorcomp, int valid[])
{
    int coordinates2[SIZE*SIZE], isuser2[SIZE*SIZE];
    int umrow2, umcolomn2;
    for (int ii = 0; ii < SIZE*SIZE; ii++)
    {
        coordinates2[ii] = coordinates[ii];
        isuser2[ii] = isuser[ii];
    }
    if (coordinates[pos] == 0)
    {
        isvalid = 0;    //reset isvalid
        coordinates2[pos] = 1;
        isuser2[pos] = *userorcomp;
        umrow2 = pos / SIZE + 1;
        umcolomn2 = pos % SIZE + 1;
        ChessRule(umrow2, umcolomn2, coordinates2, isuser2, userorcomp);
        if (isvalid == 0)
        {
            valid[pos] = 0;
        }
        else if (isvalid != 0)
        {
            valid[pos] = 1;
        }
    }
    if (coordinates[pos] == 1)
    {
        valid[pos] = 0;
    }
}

void istopass(int isuser[], int coordinates[], int*userorcomp)
{
    ispass = 0;
    int coordinates3[SIZE*SIZE], isuser3[SIZE*SIZE];
    int valid[SIZE*SIZE];
    for (int ii = 0; ii < SIZE*SIZE; ii++)
    {
        coordinates3[ii] = coordinates[ii];
        isuser3[ii] = isuser[ii];
        valid[ii] = 0;
    }
    for (int ii = 0; ii < SIZE*SIZE; ii++)
    {
        isValid(ii, coordinates3, isuser3, userorcomp, valid);
        if (valid[ii] == 0)
        {
            continue;
        }
        else if (valid[ii] > 0)
        {
            ispass = ispass + 1;
        }
    }
}

void isWin(int coordinates[], int isuser[])
{
    int userchess, compchess, chess;
    userchess = 0;
    compchess = 0;
    chess = 0;
    
    //no chess left
    iswin = 2;
    for (int ii = 0; ii < SIZE*SIZE; ii++)
    {
        if (coordinates[ii] == 1)
        {
            if (isuser[ii] == 1)
                userchess = userchess + 1;
        }
        if (coordinates[ii] == 1)
        {
            if (isuser[ii] == 0)
                compchess = compchess + 1;
        }
    }
    if (userchess == 0)
    {
        iswin = 0;
    }
    else if (compchess == 0)
    {
        iswin = 1;
    }
    
    //all board is occupied
    for (int ii = 0; ii < SIZE*SIZE; ii++)
    {
        if (coordinates[ii] == 1)
            chess = chess + 1;
    }
    if (chess == SIZE*SIZE)
    {
        if (userchess > compchess)
        {
            iswin = 1;
        }
        else if (userchess < compchess)
        {
            iswin = 0;
        }
        else if (userchess == compchess)
        {
            iswin = -1;
        }
    }
    if (iswin < 2)
    {
        printf("User: %d\n", userchess);
        printf("Computer: %d\n", compchess);
    }
    if (iswin == 1)
    {
        printf("You win!\n");
    }
    if (iswin == 0)
    {
        printf("You lose...\n");
    }
    if (iswin == -1)
    {
        printf("It is a tie!\n");
    }
}

int poslevel(int pos)
{
    int level;
    level = 0;
    for (int ii = 1; ii < SIZE-1; ii++)
    {
        if (pos == 0 || pos == SIZE*SIZE-1 || pos == SIZE*SIZE-SIZE || pos == SIZE-1)
        {
            level = 1;
            break;
        }
        else if (pos==ii || pos==ii*SIZE || pos==(ii+1)*SIZE-1 || pos==ii+SIZE*SIZE-SIZE)
        {
            level = 2;
            break;
        }
        else
        {
            continue;
        }
    }
    if (level == 0)
    {
        level = 3;
    }
    return level;
}

void MostFlip(int coordinates[], int isuser[], int consideration[], int number, int*userorcomp, int flippos[])
{
    int pcoordinates[SIZE*SIZE], pisuser[SIZE*SIZE], flip[SIZE*SIZE];
    int pumrow, pumcolomn, pmove;
    
    //copy the board and reset
    for (int ii = 0; ii < SIZE*SIZE; ii++)
    {
        pcoordinates[ii] = coordinates[ii];
        pisuser[ii] = isuser[ii];
        flip[ii] = -1;
        flippos[ii] = SIZE*SIZE;
    }
    
    //count how many can be flipped
    for (int ii = 0; ii <= number-1; ii++)
    {
        pmove = consideration[ii];
        pcoordinates[pmove] = 1;
        pisuser[pmove] = 0;
        pumrow = pmove / SIZE + 1;
        pumcolomn = pmove % SIZE + 1;
        ChessRule(pumrow, pumcolomn, pcoordinates, pisuser, userorcomp);
        flip[ii] = Flip;
        flippos[ii] = pmove;
    }
    if (number == 1)
        flippos[0] = consideration[0];
    else if (number > 1)
    {
        //sort the flippos
        for (int start = 0; start <= number-1;start = start + 1)
        {
            for(int temp = 0; temp <= number-1; temp = temp + 1)
            {
                if (flip[temp] > flip[start])
                {
                    int tem;
                    tem = flippos[temp];
                    flippos[temp] = flippos[start];
                    flippos[start] = tem;
                    tem = flip[temp];
                    flip[temp] = flip[start];
                    flip[start] = tem;
                }
            }
        }
    }
}

void CheckPath(int coordinates[], int isuser[], int *userorcomp)
{
    int pcoordinates[SIZE*SIZE], pisuser[SIZE*SIZE], valid[SIZE*SIZE];
    int pumrow, pumcolomn;
    for (int ii = 0; ii < SIZE*SIZE; ii++)
    {
        pcoordinates[SIZE] = coordinates[ii];
        pisuser[ii] = isuser[ii];
        valid[ii] = 0;
    }
    
    //check the corner before the pseudo-user moves
    int corner = 0;
    if (pcoordinates[0]==1 || pcoordinates[SIZE-1]==1 || pcoordinates[SIZE*SIZE-SIZE-1]==1 || pcoordinates[SIZE*SIZE-1]==1)
    {
        corner++;
    }
    for (int ii = 0; ii < SIZE*SIZE; ii++)
    {
        isValid(ii, pcoordinates, pisuser, userorcomp, valid);
    }
    
    //pretend to be the user
    isgarbage = 0;
    for (int ii = 0; ii < SIZE*SIZE; ii++)
    {
        if (valid[ii] > 0)
        {
            pcoordinates[ii] = 1;
            pisuser[ii] = 1;
            pumrow = ii / SIZE + 1;
            pumcolomn = ii % SIZE + 1;
            ChessRule(pumrow, pumcolomn, pcoordinates, pisuser, userorcomp);
            //count the corner again
            int corner2 = 0;
            if (pcoordinates[0]==1 || pcoordinates[SIZE-1]==1 || pcoordinates[SIZE*SIZE-SIZE-1]==1 || pcoordinates[SIZE*SIZE-1]==1)
            {
                corner2++;
            }
            if (corner == corner2)
            {
                continue;
            }
            else if (corner < corner2)
            {
                isgarbage = 1;
            }
            pcoordinates[ii] = 0;
            pisuser[ii] = 2;
        }
    }
}

void AI(int coordinates[], int isuser[], int *userorcomp)
{
    int valid[SIZE*SIZE], flippos[SIZE*SIZE];
    int consideration2[SIZE*SIZE], consideration3[SIZE*SIZE], garbage[SIZE*SIZE];
    int level, level3 = 2, levelgarbage = 3;
    int umrow2 = SIZE, umcolomn2 = SIZE;
    int c2 = 0, c3 = 0, gar = 0;
    
    //copy the board and reset
    for (int ii = 0; ii < SIZE*SIZE; ii++)
    {
        valid[ii] = 0;
        consideration2[ii] = 0;
        consideration3[ii] = 0;
    }
    
    //check all place on the board whether is valid or not
    for (int ii = 0; ii < SIZE*SIZE; ii++)
    {
        isValid(ii, coordinates, isuser, userorcomp, valid);
    }
    
    for (int ii = 0; ii < SIZE*SIZE; ii++)
    {
        if (valid[ii] > 0)
        {
            level = poslevel(ii);
            
            //take the corner if it is available
            if (level == 1)
            {
                coordinates[ii] = 1;
                isuser[ii] = 0;
                umrow2 = ii / SIZE + 1;
                umcolomn2 = ii % SIZE + 1;
                level3 = 0;
                levelgarbage = 0;
                break;
            }
            
            //collect all the other valid moves and catagorize
            else
            {
                if (level == 2)
                {
                    consideration2[c2] = ii;
                    c2 = c2 + 1;
                }
                else if (level == 3)
                {
                    consideration3[c3] = ii;
                    c3 = c3 + 1;
                }
            }
        }
    }
    
    //sides second
    if (c2 > 0)
    {
        for (int i = 0; i < c2; i++)
        {
            int i1 = 0;
            int ii = consideration2[i];
            if (poslevel(ii+1) == 1)
            {
                int iii;
                for (iii = 1; iii <= SIZE-2; iii++)
                {
                    if (isuser[ii-iii] == 1)
                    {
                        for (i1 = 1; i1 <= iii; i1++)
                        {
                            if (coordinates[ii-i1] != 1)
                            {
                                break;
                            }
                        }
                    }
                }
                if (i1 == iii+1)
                {
                    for (int i2 = i; i2 < c2; i2++)
                    {
                        consideration2[i2] = consideration2[i2+1];
                        garbage[gar] = ii;
                        gar++;
                        c2 = c2 - 1;
                    }
                    break;
                }
                else
                    continue;
            }
            else if (poslevel(ii-1) == 1)
            {
                for (int iii = 1; iii <= SIZE-2; iii++)
                {
                    if (isuser[ii+1] == 1)
                    {
                        for (i1 = 1; i1 <= iii; i1++)
                        {
                            if (coordinates[ii+i1] != 1)
                            {
                                break;
                            }
                        }
                    }
                    if (i1 == iii+1)
                    {
                        for (int i2 = i; i2 < c2; i2++)
                        {
                            consideration2[i2] = consideration2[i2+1];
                            garbage[gar] = ii;
                            gar++;
                            c2 = c2 - 1;
                        }
                        break;
                    }
                    else
                        continue;
                }
            }
            else if (ii + SIZE < SIZE*SIZE && poslevel(ii+SIZE) == 1)
            {
                for (int iii = 1; iii <= SIZE-2; iii++)
                {
                    if (isuser[ii-SIZE*iii] == 1)
                    {
                        for (i1 = 1; i1 <= iii; i1++)
                        {
                            if (coordinates[ii-SIZE*i1] != 1)
                            {
                                break;
                            }
                        }
                    }
                    if (i1 == iii+1)
                    {
                        for (int i2 = i; i2 < c2; i2++)
                        {
                            consideration2[i2] = consideration2[i2+1];
                            garbage[gar] = ii;
                            gar++;
                            c2 = c2 - 1;
                        }
                        break;
                    }
                    else
                        continue;
                }
            }
            else if (ii - SIZE >= 0 && poslevel(ii-SIZE) == 1)
            {
                for (int iii = 1; iii <= SIZE-2; iii++)
                {
                    if (isuser[ii+SIZE] == 1)
                    {
                        for (i1 = 1; i1 <= iii; i1++)
                        {
                            if (coordinates[ii+SIZE*i1] != 1)
                            {
                                break;
                            }
                        }
                    }
                    if (i1 == iii+1)
                    {
                        for (int i2 = i; i2 < c2; i2++)
                        {
                            consideration2[i2] = consideration2[i2+1];
                            garbage[gar] = ii;
                            gar++;
                            c2 = c2 - 1;
                        }
                        break;
                    }
                    else
                        continue;
                }
            }
            else
            {
                continue;
            }
        }
        if (c2 > 0)
        {
            int ii;
            int fli = 0;
            while(1)
            {
                MostFlip(coordinates, isuser, consideration2, c2, userorcomp,flippos);
                ii = flippos[fli];
                coordinates[ii] = 1;
                isuser[ii] = 0;
                umrow2 = ii / SIZE + 1;
                umcolomn2 = ii % SIZE + 1;
                ChessRule(umrow2, umcolomn2, coordinates, isuser, userorcomp);
                CheckPath(coordinates, isuser, userorcomp);
                if (isgarbage == 1)
                {
                    coordinates[ii] = 0;
                    isuser[ii] = 2;
                    fli++;
                    garbage[gar] = ii;
                    gar++;
                }
                else if (isgarbage == 0)
                {
                    break;
                }
            }
            umrow2 = ii / SIZE + 1;
            umcolomn2 = ii % SIZE + 1;
            level3 = 0;
            levelgarbage = 0;
        }
    }
    if (level3 != 0)
    {
        int i1 = 0;
        for (int i = 0; i <= c3; i++)
        {
            int ii = consideration3[i];
            if (poslevel(ii-SIZE-1) == 1)
            {
                for (int iii = 1; iii <= SIZE-2; iii++)
                {
                    if (isuser[ii+iii*SIZE+iii] == 1)
                    {
                        for (i1 = 1; i1 <= iii; i1++)
                        {
                            if (coordinates[ii+i1*SIZE+i1] != 1)
                            {
                                break;
                            }
                        }
                        if (i1 == iii + 1)
                        {
                            for (int i2 = i; i2 < c3; i2++)
                            {
                                consideration3[i2] = consideration3[i2+1];
                                garbage[gar] = ii;
                                gar++;
                                c3 = c3 - 1;
                            }
                            break;
                        }
                        else
                            continue;
                    }
                }
            }
            if (poslevel(ii-SIZE+1) == 1)
            {
                for (int iii = 1; iii <= SIZE-2; iii++)
                {
                    if (isuser[ii+iii*SIZE-iii] == 1)
                    {
                        for (i1 = 1; i1 < iii; i1++)
                        {
                            if (coordinates[ii+i1*SIZE-i1] != 1)
                            {
                                break;
                            }
                        }
                        if (i1 == iii + 1)
                        {
                            for (int i2 = i; i2 < c3; i2++)
                            {
                                consideration3[i2] = consideration3[i2+1];
                                garbage[gar] = ii;
                                gar++;
                                c3 = c3 - 1;
                            }
                            break;
                        }
                        else
                            continue;
                    }
                }
            }
            if (poslevel(ii+SIZE-1) == 1)
            {
                for (int iii = 1; iii <= SIZE-2; iii++)
                {
                    if (isuser[ii-iii*SIZE+iii] == 1)
                    {
                        for (i1 = 1; i1 < iii; i1++)
                        {
                            if (coordinates[ii-i1*SIZE+i1] != 1)
                            {
                                break;
                            }
                        }
                        if (i1 == iii)
                        {
                            for (int i2 = i; i2 < c3; i2++)
                            {
                                consideration3[i2] = consideration3[i2+1];
                                garbage[gar] = ii;
                                gar++;
                                c3 = c3 - 1;
                            }
                            break;
                        }
                        else
                            continue;
                    }
                }
            }
            if (poslevel(ii+SIZE+1) == 1)
            {
                for (int iii = 1; iii <= SIZE-2; iii++)
                {
                    if (isuser[ii-iii*SIZE-iii] == 1)
                    {
                        for (i1 = 1; i1 < iii; i1++)
                        {
                            if (coordinates[ii-i1*SIZE-i1] != 1)
                            {
                                break;
                            }
                        }
                    }
                    if (i1 == iii)
                    {
                        for (int i2 = i; i2 < c3; i2++)
                        {
                            consideration3[i2] = consideration3[i2+1];
                            garbage[gar] = ii;
                            gar++;
                            c3 = c3 - 1;
                        }
                        break;
                    }
                    else
                        continue;
                }
            }
            else
            {
                continue;
            }
        }
        if (c3 > 0)
        {
            int ii;
            int fli = 0;
            while(1)
            {
                MostFlip(coordinates, isuser, consideration3, c3, userorcomp,flippos);
                ii = flippos[fli];
                coordinates[ii] = 1;
                isuser[ii] = 0;
                umrow2 = ii / SIZE + 1;
                umcolomn2 = ii % SIZE + 1;
                ChessRule(umrow2, umcolomn2, coordinates, isuser, userorcomp);
                CheckPath(coordinates, isuser, userorcomp);
                if (isgarbage == 1)
                {
                    coordinates[ii] = 0;
                    isuser[ii] = 2;
                    fli++;
                    garbage[gar] = ii;
                    gar++;
                }
                else if (isgarbage == 0)
                {
                    break;
                }
            }
            umrow2 = ii / SIZE + 1;
            umcolomn2 = ii % SIZE + 1;
            levelgarbage = 0;
        }
    }
    if (levelgarbage != 0)
    {
        int ii;
        int fli = 0;
        while(1)
        {
            MostFlip(coordinates, isuser, garbage, gar, userorcomp,flippos);
            ii = flippos[fli];
            coordinates[ii] = 1;
            isuser[ii] = 0;
            umrow2 = ii / SIZE + 1;
            umcolomn2 = ii % SIZE + 1;
            ChessRule(umrow2, umcolomn2, coordinates, isuser, userorcomp);
            CheckPath(coordinates, isuser, userorcomp);
            if (isgarbage == 1)
            {
                coordinates[ii] = 0;
                isuser[ii] = 2;
                fli++;
            }
            else if (isgarbage == 0)
            {
                break;
            }
        }
        umrow2 = ii / SIZE + 1;
        umcolomn2 = ii % SIZE + 1;
    }
    ChessRule(umrow2, umcolomn2, coordinates, isuser, userorcomp);
}

int main()
{
    int coordinates[SIZE*SIZE], coordinates2[SIZE*SIZE], isuser[SIZE*SIZE], isuser2[SIZE*SIZE];
    char usermove[3];
    int* userorcomp = NULL;
    int userchess = 0, compchess = 0;
    char isplay;
    for (int ii = 0; ii <= SIZE*SIZE-1; ii++)
    {
        coordinates[ii] = 0;
        isuser[ii] = 2;
    }
    //set the four chesses on the initial board
    coordinates[SIZE*(SIZE/2-1)+SIZE/2-1] = 1;
    isuser[SIZE*(SIZE/2-1)+SIZE/2-1] = 1;
    coordinates[SIZE*(SIZE/2-1)+SIZE/2] = 1;
    isuser[SIZE*(SIZE/2-1)+SIZE/2] = 0;
    coordinates[SIZE*(SIZE/2)+SIZE/2-1] = 1;
    isuser[SIZE*(SIZE/2)+SIZE/2-1] = 0;
    coordinates[SIZE*(SIZE/2)+SIZE/2] = 1;
    isuser[SIZE*(SIZE/2)+SIZE/2] = 1;
//    coordinates[43] = 1;
//    isuser[43] = 1;
//    coordinates[42] = 1;
//    isuser[42] = 0;
//    coordinates[0] = 1;
//    isuser[0] = 0;
//    coordinates[1] = 1;
//    isuser[1] = 0;
//    coordinates[2] = 1;
//    isuser[2] = 0;
//    coordinates[8] = 1;
//    isuser[8] = 1;
//    coordinates[16] = 1;
//    isuser[16] = 0;
//    coordinates[33] = 1;
//    isuser[33] = 1;
//    coordinates[18] = 1;
//    isuser[18] = 0;
//    coordinates[27] = 1;
//    isuser[27] = 1;
//    coordinates[36] = 1;
//    isuser[36] = 0;
//    coordinates[63] = 1;
//    isuser[63] = 1;
//    coordinates[62] = 1;
//    isuser[62] = 0;
//    coordinates[61] = 1;
//    isuser[61] = 1;
//    coordinates[60] = 1;
//    isuser[60] = 0;
    ChessBoard(coordinates,isuser);
    isvalid = 0;
    int uorc = 0;
    userorcomp = &uorc;
    while(1)
    {
        //copy a board in case the input move is invalid
        for (int ii = 0; ii <= SIZE*SIZE-1; ii++)
        {
            coordinates2[ii] = coordinates[ii];
            isuser2[ii] = isuser[ii];
        }
        *userorcomp = 1 - *userorcomp;
        
        //check if game is over
        isWin(coordinates,isuser);
        
        if (iswin < 2)
        {
            printf("Do you want to play again? (y/n)\n");
            scanf("%s",&isplay);
            if (isplay == 'y')
            {
                main();
                break;
            }
            else if (isplay == 'n')
            {
                break;
            }
        }
        
        else if (iswin > 1)
        {
            //check if need to pass first
            istopass(isuser, coordinates, userorcomp);
            
            while (ispass == 0)
            {
                isdoublepass = isdoublepass + 1;
                printf("You have to pass this move.\n");
                
                //check if both pass
                if (isdoublepass == 2)//exit the game
                {
                    for (int ii = 0; ii < SIZE*SIZE; ii++)
                    {
                        if (coordinates[ii] == 1)
                        {
                            if (isuser[ii] == 1)
                                userchess = userchess + 1;
                            else if (isuser[ii] == 0)
                                compchess = compchess + 1;
                        }
                    }
                    printf("User: %d\n", userchess);
                    printf("Computer: %d\n", compchess);
                    printf("It is a tie!\n");
                    iswin = -1;
                }
                break;
            }
        
            //user to move
            if (ispass != 0)
            {
                isdoublepass = 0;   //reset the isdoublepass to recount
                printf("%s","Please enter your move <row colomn - no space>: ");
                scanf("%s",usermove);
                UserMove(usermove,coordinates,isuser,userorcomp);
                
                //check if is valid
                if (isvalid != 0)
                {
                    ChessBoard(coordinates,isuser);
                }

                while (isvalid == 0)
                {
                    printf("%s\n","This is not a valid move.");
                    ChessBoard(coordinates2,isuser2);
                    //reset the chess board to the former state
                    for (int ii = 0; ii < SIZE*SIZE; ii++)
                    {
                        coordinates[ii] = coordinates2[ii];
                        isuser[ii] = isuser2[ii];
                    }
                    printf("%s","Please enter your move <row colomn - no space>: ");
                    scanf("%s",usermove);
                    UserMove(usermove,coordinates,isuser,userorcomp);
                    ChessBoard(coordinates,isuser);
                }
            }
        }
        
        //computer to move
        
        //change the chess
        *userorcomp = 1 - *userorcomp;
        
        //check if the game is over
        isWin(coordinates,isuser);
        
        if (iswin <=1)
        {
            printf("Do you want to play again? (y/n)\n");
            scanf("%s",&isplay);
            if (isplay == 'y')
            {
                main();
                break;
            }
            else if (isplay == 'n')
            {
                break;
            }
        }
        
        if (iswin > 1)
        {
            //check if to pass
            istopass(isuser, coordinates, userorcomp);
        
            if (ispass == 0)
            {
                isdoublepass = isdoublepass + 1;
                printf("Computer has to pass this move.\n");
                
                if (isdoublepass == 2)
                {
                    for (int ii = 0; ii < SIZE*SIZE; ii++)
                    {
                        if (coordinates[ii] == 1)
                        {
                            if (isuser[ii] == 1)
                                userchess = userchess + 1;
                            else if (isuser[ii] == 0)
                                compchess = compchess + 1;
                        }
                    }
                    printf("User: %d\n", userchess);
                    printf("Computer: %d\n", compchess);
                    printf("It is a tie!\n");
                    iswin = -1;
                    break;
                }
            }
            
            if (ispass != 0)
            {
                isdoublepass = 0;   //reset the isdoublepass to recount
                
                //AI to calculate the position
                AI(coordinates, isuser, userorcomp);
                
                //form the chessboard
                ChessBoard(coordinates,isuser);
                
                //reset isvalid to check the user's move
                isvalid = 0;
            }
        }
    }
}
































