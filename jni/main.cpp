#include <jni.h>
#include <dlfcn.h>
#include <Substrate.h>

#include "minecraftpe/client/Minecraft.h"
#include "minecraftpe/network/SharedConstants.h"

std::string servername="";
int maxplayers=5;
int chatlength=100;

#include "DataSave.h"

std::string (*_Minecraft$getServerName)();
std::string Minecraft$getServerName(){
return servername;
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
DataSave();
SharedConstants::MaxChatLength=chatlength;
SharedConstants::NetworkDefaultMaxPlayers=maxplayers;
if(servername!=""){
MSHookFunction((void*)&Minecraft::getServerName,(void*)&Minecraft$getServerName,(void**)&_Minecraft$getServerName);
}
return JNI_VERSION_1_2;
}
