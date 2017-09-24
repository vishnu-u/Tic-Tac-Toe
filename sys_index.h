/* Defines algorithm for finding indexe for Tic-Tac-Toe Game*/

int systemIndexFind(char game_data[],char key_1,char key_2)
{

//provides condition for placing system token
if(game_data[0] == key_2 &&
   game_data[3] == key_2 && 
   
   game_data[6] != key_1 && 
   game_data[6] != key_2)
{
 return 6;
}

else if(game_data[3] == key_2 &&
        game_data[6] == key_2 &&
        
        game_data[0] != key_1 &&
        game_data[0] != key_2)
{
return 0;
}


else if(game_data[0] == key_2 &&
        game_data[6] == key_2 &&
        
         game_data[3] != key_1 &&
         game_data[3] != key_2)

{
return 3;
}

else if(game_data[1] == key_2 &&
        game_data[4] == key_2 &&
        game_data[7] != key_2 &&
        game_data[7] != key_1)
{
return 7;
}

else if(game_data[4] == key_2 &&
        game_data[7] == key_2 &&
        game_data[1] != key_1 &&
        game_data[1] != key_2)
{
return 1;
}

else if(game_data[1] == key_2 &&
        game_data[7] == key_2 &&
        game_data[4] != key_1 &&
        game_data[4] != key_2)
{
return 4;
}

else if(game_data[2] == key_2 &&
        game_data[5] == key_2 &&
        game_data[8] != key_1 &&
        game_data[8] != key_2)
{
return 8;
}

else if(game_data[5] == key_2 &&
        game_data[8] == key_2 && 
        game_data[2] != key_1 && 
        game_data[2] != key_2)
{
return 2;
}

else if(game_data[8] == key_2 &&
        game_data[2] == key_2 &&
        game_data[5] != key_1 &&
        game_data[5] != key_2)
{
return 5;
}

else if(game_data[0] == key_2 &&
        game_data[1] == key_2 &&
        game_data[2] != key_1 &&
        game_data[2] != key_2)
{
return 2;
}


else if(game_data[1] == key_2 &&
        game_data[2] == key_2 &&
        game_data[0] != key_1 &&
        game_data[0] != key_2)
{
return 0;
}

else if(game_data[2] == key_2 &&
        game_data[0] == key_2 &&
        game_data[1] != key_1 &&
        game_data[1] != key_2)
{
return 1;
}

else if(game_data[3] == key_2 &&
        game_data[4] == key_2 &&
        game_data[5] != key_1 &&
        game_data[5] != key_2)
{
return 5;
}

else if(game_data[4] == key_2 &&
        game_data[5] == key_2 &&
        game_data[3] != key_1 &&
        game_data[3] != key_2)
{
return 3;
}

else if(game_data[5] == key_2 &&
        game_data[3] == key_2 &&
        game_data[4] != key_1 &&
        game_data[4] != key_2)
{
return 4;
}

else if(game_data[6] == key_2 &&
        game_data[7] == key_2 &&
        game_data[8] != key_1 &&
        game_data[8] != key_2)
{
return 8;
}

else if(game_data[7] == key_2 &&
        game_data[8] == key_2 &&
        game_data[6] != key_1 && 
	game_data[6] != key_2)
{
return 6;
}

else if(game_data[8] == key_2 &&
        game_data[6] == key_2 &&
	game_data[7] != key_1 &&
	game_data[7] != key_2)
{
return 7;
}

else if(game_data[0] == key_2 &&
        game_data[4] == key_2 &&
        game_data[8] != key_2 &&
        game_data[8] != key_1)
{
return 8;
}

else if(game_data[4] == key_2 &&
        game_data[8] == key_2 &&
        game_data[0] != key_1 &&
        game_data[0] != key_2)
{
return 0;
}

else if(game_data[0] == key_2 &&
        game_data[8] == key_2 &&
        game_data[4] != key_1 &&
        game_data[4] != key_2)
{
return 4;
}

else if(game_data[6] == key_2 &&
        game_data[4] == key_2 &&
        game_data[2] != key_1 &&
        game_data[2] != key_2)
{
return 2;
}

else if(game_data[4] == key_2 &&
        game_data[2] == key_2 &&
        game_data[6] != key_1 &&
        game_data[6] != key_2)
{
return 6;
}

else if(game_data[6] == key_2 &&
        game_data[2] == key_2 &&
        game_data[4] != key_1 &&
        game_data[4] != key_2)
{
return 4;
}


return -1;
}

