#include <bits/stdc++.h>
using namespace std;

char calDirection (char pos, char command){
    if((command)=='l'){
        if(pos=='n'){
            pos='w';
        }
       else if(pos=='s'){
            pos='e';
        }
        else if(pos=='e'){
            pos='n';
        }
        else if(pos=='w'){
            pos='s';
        }
    }
    if((command)=='r'){
        if(pos=='n'){
            pos='e';
        }
       else if(pos=='s'){
            pos='w';
        }
        else if(pos=='e'){
            pos='s';
        }
        else if(pos=='w'){
            pos='n';
        }
    }
    if(command=='u'){
        pos='u';
    }
    if(command=='d'){
        pos='d';
    }

    return pos;

}

int calLocation(int x,int y,int z, char commands[], int size ){
    char pos = 'n';
    bool zActive = false;
    char zPos = 'u';
    for(int i=0;i<size;i++){
        char curr = commands[i];
        if(curr=='l' || curr=='r'){
          pos = calDirection(pos,curr);
          zActive= false;

        }
        else if(curr=='u' || curr=='d') {
            zPos= curr;
            zActive= true;
        }
        if(zActive== false){
         if(pos=='n'){
           if(curr=='f'){
               y++;
           }
           else if (curr=='b'){
               y--;
           }
        }
        if(pos=='s'){
            if(curr=='f'){
                y--;
            }
            else if (curr=='b'){
                y++;
            }
        }
        if(pos=='e'){
            if(curr=='f'){
                x++;
            }
            if(curr=='b'){
                x--;
            }
        }
        if(pos=='w'){
            if(curr=='f'){
                x--;
            }
            if(curr=='b'){
                x++;
            }
        }
        }
        if(zPos=='u' && zActive==true){
            if(curr=='f'){
                z++;
            }
            if(curr=='b'){
                z--;
            }
        }
        if(zPos=='d' && zActive==true){
            if(curr=='f'){
                z--;
            }
            if(curr=='b'){
                z++;
            }
        }

    }
   // final coordinate of the chandrayan3 rover is
   cout <<"("<<x<<","<<y<<","<<z<<")"<<endl;
   if(zActive== true){
       cout<<char(toupper(zPos))<<endl;
       return 0;
   } 

   cout << char(toupper(pos))<<endl;
    return 0;
}
int main() {
    //taking command inputs 
    int n;
    cin>>n;
    char charCommand[n];
    for(int i=0;i<n;i++){
        cin>>charCommand[i];
    }
    int x_cor=0;
    int y_cor=0;
    int z_cor=0;
    calLocation(x_cor,y_cor,z_cor,charCommand,n);

}
