#include "HecticFeedback.hpp"

void FeedbackPerformer::SetMinDelay(std::chrono::milliseconds value) {
    minDelay = value;
}

std::chrono::milliseconds FeedbackPerformer::GetMinDelay() {
    return minDelay;
}

std::chrono::milliseconds FeedbackPerformer::GetElapsed() {
    return elapsed;
}

void FeedbackPerformer::Perform(FeedbackType type) {
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();

    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastEvent);

#ifdef HACTIC_DEBUG
    HEC_DEBUG_LOG_INFO("Elapsed: " + std::to_string(elapsed.count()));
#endif

    if(elapsed < minDelay) {
#ifdef HACTIC_DEBUG
    HEC_DEBUG_LOG_INFO("Can't trigger: Minimum delay is  " + std::to_string(minDelay.count()) + "ms but only " + std::to_string(elapsed.count()) + "ms have passed. ");
#endif
    } else {
        haptic_trigger(type);
    }

    lastEvent = std::chrono::steady_clock::now();
}

FeedbackPerformer::FeedbackPerformer() {
    // Default delay = 33ms / max. 30 fps
    minDelay = std::chrono::milliseconds(33);
    elapsed = std::chrono::milliseconds(0);
    lastEvent = std::chrono::steady_clock::now();
}