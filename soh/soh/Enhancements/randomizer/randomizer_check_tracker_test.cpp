#include "randomizer_check_tracker.h"
#include "soh/Enhancements/randomizer/randomizerTypes.h"
#include "z64.h"
#include "z64save.h"

#include <gtest/gtest.h>

extern "C" {
#include "variables.h"
}

namespace CheckTracker {
namespace {

// The fixture for testing class Foo.
class CheckTrackerTest : public testing::Test {
  protected:
    // You can remove any or all of the following functions if their bodies would
    // be empty.

    CheckTrackerTest() {
    }

    ~CheckTrackerTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(CheckTrackerTest, ShowsHeartPiecesWhenNotInARandomizer) {
    RandomizerCheck rc = RC_GRAVEYARD_HEART_PIECE_GRAVE_CHEST;

    // set the global state of our check to saved with a preference to show
    gSaveContext.checkTrackerData[rc].status = RCSHOW_SAVED;
    // setup gSaveContext to not be a randomizer
    gSaveContext.questId = QUEST_NORMAL;
    // setup gSaveContext to use English language
    gSaveContext.language = LANGUAGE_ENG;

    RandomizerCheckObject heartPiece = {
        rc,
        RCVORMQ_BOTH,
        RCTYPE_STANDARD,
        RCAREA_GRAVEYARD,
        ACTOR_EN_BOX,
        SCENE_REDEAD_GRAVE,
        -22592,
        GI_HEART_PIECE,
        false,
        "Heart Piece Grave Chest",
        "GY Heart Piece Grave Chest",
        true
    };

    EXPECT_EQ(extraInfo(heartPiece), "Piece of Heart");
}

} // namespace
} // namespace CheckTracker

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
