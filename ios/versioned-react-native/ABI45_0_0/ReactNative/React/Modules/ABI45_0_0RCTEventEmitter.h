/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <ABI45_0_0React/ABI45_0_0RCTBridge.h>

/**
 * ABI45_0_0RCTEventEmitter is an abstract base class to be used for modules that emit
 * events to be observed by JS.
 */
@interface ABI45_0_0RCTEventEmitter : NSObject <ABI45_0_0RCTBridgeModule, ABI45_0_0RCTInvalidating>

@property (nonatomic, weak) ABI45_0_0RCTBridge *bridge;
@property (nonatomic, weak) ABI45_0_0RCTModuleRegistry *moduleRegistry;
@property (nonatomic, weak) ABI45_0_0RCTViewRegistry *viewRegistry_DEPRECATED;

- (instancetype)initWithDisabledObservation;

/**
 * Override this method to return an array of supported event names. Attempting
 * to observe or send an event that isn't included in this list will result in
 * an error.
 */
- (NSArray<NSString *> *)supportedEvents;

/**
 * Send an event that does not relate to a specific view, e.g. a navigation
 * or data update notification.
 */
- (void)sendEventWithName:(NSString *)name body:(id)body;

/**
 * These methods will be called when the first observer is added and when the
 * last observer is removed (or when dealloc is called), respectively. These
 * should be overridden in your subclass in order to start/stop sending events.
 */
- (void)startObserving;
- (void)stopObserving;

- (void)invalidate NS_REQUIRES_SUPER;

- (void)addListener:(NSString *)eventName;
- (void)removeListeners:(double)count;

@end
