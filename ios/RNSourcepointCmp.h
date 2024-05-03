
#ifdef RCT_NEW_ARCH_ENABLED
#import "Spec.h"

@interface RNSourcepointCmp : NSObject <Spec>
#else
#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>

#import "sourcepoint_react_native_cmp-Swift.h"

@interface RCT_EXTERN_MODULE(RNSourcepointCmp, RCTEventEmitter)

RCT_EXTERN_METHOD(build:(int)accountId propertyId:(int)propertyId propertyName:(NSString *)propertyName campaigns:(SPCampaigns*)campaigns)

RCT_EXTERN_METHOD(loadMessage)
RCT_EXTERN_METHOD(clearLocalData)
RCT_EXTERN_METHOD(loadGDPRPrivacyManager:(NSString *)pmId)
RCT_EXTERN_METHOD(loadUSNatPrivacyManager:(NSString *)pmId)

RCT_EXTERN_METHOD(getUserData: (RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject)

RCT_EXTERN_METHOD(supportedEvents)

+ (BOOL)requiresMainQueueSetup
{
    return YES;
}

/// TODO: check if this really can be here or need fixing in the SDK
/// https://reactnative.dev/docs/native-modules-ios
/// https://github.com/OneSignal/react-native-onesignal/issues/749
- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

// Don't compile this code when we build for the old architecture.
#ifdef RCT_NEW_ARCH_ENABLED
- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
(const facebook::react::ObjCTurboModule::InitParams &)params
{
    return std::make_shared<facebook::react::NativeSpecJSI>(params);
}
#endif

@end
#endif
