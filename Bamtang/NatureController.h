#include "INature.h"
#include "ITimeEvent.h"

#include "VectorV1Nature.h"
#include "VectorV2Nature.h"
#include "VectorV3Nature.h"
#include "VectorV4Nature.h"

#include "ForceV1Nature.h"
#include "ForceV2Nature.h"
#include "ForceV3Nature.h"
#include "ForceV4Nature.h"

namespace NatureLab
{
    class NatureController
    {
    public:

        static NatureController* Instance(){
            static NatureController instance;
            return &instance;
        }

        inline NatureController(){

            SceneAssets::loadShader("Assets/Shaders/sprite.vert", "Assets/Shaders/sprite.frag", nullptr, "sprite");
            SceneAssets::loadTexture("Assets/Sprites/background.jpg", false, "background");
            SceneAssets::loadTexture("Assets/Sprites/ball.png", true, "ball");
            SceneAssets::loadTexture("Assets/Sprites/paddle.png", true, "paddle");
            //SceneAssets::loadTexture("Assets/Sprites/block.png", true, "block");
            SceneAssets::loadTexture("Assets/Sprites/red.png", true, "red");
            SceneAssets::loadTexture("Assets/Sprites/blue.png", true, "blue");
            SceneAssets::loadTexture("Assets/Sprites/sun.png", true, "sun");

            this->start();
        }

        inline void start() {
            this->addNature(new VectorV1Nature());
            this->addNature(new VectorV2Nature());
            this->addNature(new VectorV3Nature());
            this->addNature(new VectorV4Nature());

            this->addNature(new ForceV1Nature());
            this->addNature(new ForceV2Nature());
            this->addNature(new ForceV3Nature());
            this->addNature(new ForceV4Nature());
        }

        inline void showNature(){
            for (NatureLab::INature*& inteface : _natureLab)
            {
                inteface->show();
            }
        }

        inline void showNature(int indexScene) {
            _natureLab.at(indexScene)->show();
        }

        inline INature*& getNature(int index)
        {
            return _natureLab.at(index);
        }

    private:
    
        inline void addNature(NatureLab::INature* nature){
            this->_natureLab.push_back(nature);
        }

    private:

        std::vector<NatureLab::INature*> _natureLab;

    };

}