#include "MutateCommand.h"

MutateCommand::MutateCommand(std::shared_ptr<GameEngine> engine,
                             std::shared_ptr<Population> population,
                             Population::MutationType type) :
                             goal(std::move(population)), mutationType(type) {
  setReceiver(std::move(engine));
}

bool MutateCommand::execute() {

}
