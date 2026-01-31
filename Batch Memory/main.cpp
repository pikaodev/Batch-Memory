/*
Made by pikao.dev

What can I use this for? 
Use this for any script you have if you wish to not write it to disk.
This can be used for basically anything; using stdin to send the commands to cmd.exe which is the best way to do it as far as I know.

Please leave a star on this GitHub repo if you found it helpful <3

*/

#include "batch_exec.h"
#include "batch_script.h"

int main()
{
    BatMem(batchScript); // this is what we use to call the script we have stored in our code. 
    return 0;
}
