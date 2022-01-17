#include <mod/amlmod.h>

#define GL_GLEXT_PROTOTYPES
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

MYMOD(net.rusjj.glalphafunc, GLAlphaFunc Crash Fix, 1.0, RusJJ)

uintptr_t pGameLib = 0;
extern "C" void OnModLoad()
{
    pGameLib = aml->GetLib("libGTASA.so");
    if(pGameLib)
    {
        aml->Unprot(pGameLib + 0x6BCBF8, sizeof(void*));
        *(void**)(pGameLib + 0x6BCBF8) = (void*)glAlphaFuncQCOM;
        return;
    }

    pGameLib = aml->GetLib("libGTAVC.so");
    if(pGameLib)
    {
        aml->Unprot(pGameLib + 0x7300E0, sizeof(void*));
        *(void**)(pGameLib + 0x7300E0) = (void*)glAlphaFuncQCOM;
        return;
    }   
}