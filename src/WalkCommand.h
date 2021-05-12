//
// Created by galqiwi on 09.05.2021.
//

#ifndef ATP_SHOOTER_WALKCOMMAND_H
#define ATP_SHOOTER_WALKCOMMAND_H

#include "InputCommand.h"

class WalkCommand: public InputCommand {
public:
    WalkCommand(Scene* scene, Vector2D action, double dt);

    void Execute() override;
private:
    Scene* scene_;
    Vector2D action_;
    double dt_;
};


#endif //ATP_SHOOTER_WALKCOMMAND_H
