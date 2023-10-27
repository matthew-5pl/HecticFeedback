#include "HecticFeedback.hpp"
#include <chrono>
#include <thread>

int main() {
    FeedbackPerformer performer;
    HEC_DEBUG_LOG_INFO("Testing feedback type 1: Generic");
    performer.WaitAndPerform(FeedbackType::Generic);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    HEC_DEBUG_LOG_INFO("Testing feedback type 2: Alignment");
    performer.WaitAndPerform(FeedbackType::Alignment);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    HEC_DEBUG_LOG_INFO("Testing feedback type 3: LevelChange");
    performer.WaitAndPerform(FeedbackType::LevelChange);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    return 0;
}