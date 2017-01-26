#include <iostream>
#include <fstream>
#include <stdlib.h>

void DataSave(){
std::string path="/sdcard/games/com.mojang/minecraftpe/servereditor.txt";
std::string temp;
bool flag=false;
std::ifstream istreamA(path);
if(!istreamA){
std::ofstream ostream(path);
if(!ostream){
return;
}
ostream
<<"ServerName="<<std::endl
<<"MaxPlayers=5"<<std::endl
<<"ChatLength=100"<<std::endl;
ostream.close();
}
std::ifstream istreamB(path);
while(istreamB&&getline(istreamB,temp)){
if(temp.find("ServerName=")!=std::string::npos){
servername=temp.replace(0,11,"");
}
else if(temp.find("MaxPlayers=")!=std::string::npos){
maxplayers=atoi(temp.replace(0,11,"").c_str());
}
if(temp.find("ChatLength=")==std::string::npos){
chatlength=atoi(temp.replace(0,11,"").c_str());
}
}
istreamB.close();
}