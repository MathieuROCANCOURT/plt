#include "Command.h"

const engine::CommandTypeId engine::Command::getTypeId() {
    return this->CommandId;
}

engine::Command::Command(engine::CommandTypeId TypeID) {
    this->CommandId=TypeID;
}

engine::Command::~Command() {

}
/*
void engine::Command::execute(state::State &state) {
    switch (this->getTypeId()) {
        case ROLLDICES:
            dynamic_cast<>(expression)
    }
}
*/