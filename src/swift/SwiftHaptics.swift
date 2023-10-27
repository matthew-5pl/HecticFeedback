import AppKit

@_cdecl("haptic_trigger")
public func haptic_trigger(_ type: Int) {
    NSHapticFeedbackManager.defaultPerformer.perform(NSHapticFeedbackManager.FeedbackPattern.init(rawValue: type)!, performanceTime: NSHapticFeedbackManager.PerformanceTime.now)
}