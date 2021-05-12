//
// Created by galqiwi on 09.05.2021.
//

#include "InputCommand.h"
#include "InputCommandDecorator.h"
#include "GraphicsFacade.h"
#include "LoadDecorator.h"
#include "SaveDecorator.h"
#include "WalkCommand.h"

std::shared_ptr<InputCommand> InputCommand::GetCommand(Scene* scene, Scene::SceneSnapshotHolder* scene_snapshot_holder,
                                                       double dt) {

    auto buttons_pressed = GraphicsFacade::GetButtonsPressed();
    InputCommandPtr out = std::make_shared<WalkCommand>(scene, buttons_pressed.GetAction(), dt);

    if (buttons_pressed.quick_save) {
        out = std::make_shared<SaveDecorator>(out, scene_snapshot_holder);
    }
    if (buttons_pressed.quick_load) {
        out = std::make_shared<LoadDecorator>(out, scene_snapshot_holder);
    }
    return out;
}
