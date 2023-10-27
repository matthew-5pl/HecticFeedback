#ifndef HECTIC_FEEDBACK_HPP
#define HECTIC_FEEDBACK_HPP

#include <iostream>
#include <chrono>
#include <thread>

#define HEC_DEBUG_LOG_INFO(x) std::cout << "HecticFeedback/Debug/Info: " << x << std::endl
#define HEC_DEBUG_LOG_ERR(x) std::cout << "HecticFeedback/Debug/Error: " << x << std::endl

// You should not call this directly! Please use the HecticFeedback class.
extern "C" void haptic_trigger(int type);

// Feedback type, pretty much equivalent to:
// https://developer.apple.com/documentation/appkit/nshapticfeedbackmanager/feedbackpattern
enum FeedbackType {
    Generic = 0,
    Alignment,
    LevelChange
};

// A class that can programmatically perform haptic feedback events.
class FeedbackPerformer {
private:
    // Minimum delay in milliseconds between feedback.
    // Can be set to not stress the haptic motors too much.
    std::chrono::milliseconds minDelay;
    // Time elapsed since last feedback event.
    std::chrono::milliseconds elapsed;
    // Timestamp where last feedback event occured.
    std::chrono::steady_clock::time_point lastEvent;
public:
    // Set the minimum delay (in milliseconds) between feedback events.
    void SetMinDelay(std::chrono::milliseconds value);
    // Get the minimum delay (in milliseconds) between feedback events.
    std::chrono::milliseconds GetMinDelay();
    // Get the amount of time (in milliseconds) elapsed since last feedback event.
    std::chrono::milliseconds GetElapsed();
    // Perform feedback.
    // @param type Type of feedback to send, changes haptic feel
    void Perform(FeedbackType type);
    // Wait in this thread for the set delay time.
    void Wait();
    // Wait in this thread for the set delay time, then perform feedback.
    // Equivalent to calling Wait() and Perform().
    void WaitAndPerform(FeedbackType type);
    // Constructor.
    FeedbackPerformer();
};

#endif