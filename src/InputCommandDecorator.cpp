//
// Created by galqiwi on 09.05.2021.
//

#include "InputCommandDecorator.h"

InputCommandDecorator::InputCommandDecorator(InputCommandPtr wrappee): wrappee_(wrappee) {

}

void InputCommandDecorator::Execute() {
    wrappee_->Execute();
}
