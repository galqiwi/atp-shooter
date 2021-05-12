//
// Created by galqiwi on 09.05.2021.
//

#ifndef ATP_SHOOTER_INPUTCOMMANDDECORATOR_H
#define ATP_SHOOTER_INPUTCOMMANDDECORATOR_H

#include "InputCommand.h"

using InputCommandPtr = std::shared_ptr<InputCommand>;

class InputCommandDecorator: public InputCommand {
public:
    InputCommandDecorator(InputCommandPtr wrappee);

    void Execute() override;
private:
    InputCommandPtr wrappee_;
};


#endif //ATP_SHOOTER_INPUTCOMMANDDECORATOR_H
