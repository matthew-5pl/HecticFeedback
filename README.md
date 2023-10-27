# HecticFeedback
A tiny C++ Haptic Feedback library for Mac trackpads!

# How does it work?
HecticFeedback takes advantage of Swift/C++ Interop to call AppKit APIs and trigger haptic feedback.

# How do I use it?
HecticFeedback is very easy to use! This is a basic example:

```cpp
#include "HecticFeedback.hpp"

int main() {
    FeedbackPerformer performer;
    performer.Perform(FeedbackType::Generic);

    return 0;
}
```

You can find more examples in the `tests/` folder.