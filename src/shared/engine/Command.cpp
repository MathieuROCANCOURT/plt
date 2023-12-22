#include "Command.h"

const engine::CommandTypeId engine::Command::getTypeId() {
    return this->CommandId;
}

engine::Command::Command(engine::CommandTypeId TypeID) {
    this->CommandId=TypeID;
}
