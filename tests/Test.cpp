#include "HecticFeedback.hpp"
#include <chrono>
#include <thread>

int main() {
    FeedbackPerformer performer;
    HEC_DEBUG_LOG_INFO("Testing delays: this loop should NOT work!");
    for(int i = 0; i < 10; i++) {
        performer.Perform(FeedbackType::Generic);
    }
    HEC_DEBUG_LOG_INFO("Testing delays: this loop should work!");
    for(int i = 0; i < 10; i++) {
        performer.Perform(FeedbackType::Generic);
        std::this_thread::sleep_for(std::chrono::milliseconds(34));
    }
    return 0;
}