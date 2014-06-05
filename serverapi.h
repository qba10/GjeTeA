#ifndef SERVERAPI_H
#define SERVERAPI_H
#include "serverconnectapi.h"
namespace SSJ {

    class ServerApi
    {
    private:
        static MainPlayer * pointerMainPlayer;
        static void CreateRequest(string request, Json::Value parametres = Json::nullValue);
    public:
        static void AskToCreateMainPlayer();
        static void AskToSynchronizeMainPlayer();
		static void AskToCreateBullet(Json::Value parameters);
		static void AskToCreateWeapon(Json::Value parameters);
    };
}
#endif // SERVERAPI_H
