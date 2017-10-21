#include "slGame.h"
#include "slGameState.h"
#include "Playbed.h"

int main() {
	slGame::Init("Test", 800, 480);
	slGame::inst.Run(new Playbed);
}