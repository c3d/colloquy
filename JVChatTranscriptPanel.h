#import "JVChatWindowController.h"

@class JVStyleView;
@class MVMenuButton;
@class JVStyle;
@class JVEmoticonSet;
@class JVChatMessage;
@class JVChatTranscript;

extern NSString *JVToolbarChooseStyleItemIdentifier;
extern NSString *JVToolbarEmoticonsItemIdentifier;
extern NSString *JVToolbarFindItemIdentifier;

@interface JVChatTranscriptPanel : NSObject <JVChatViewController, JVChatViewControllerScripting> {
	@protected
	IBOutlet NSView *contents;
	IBOutlet JVStyleView *display;
	BOOL _nibLoaded;

	JVChatWindowController *_windowController;

	JVChatTranscript *_transcript;

	NSMenu *_styleMenu;
	NSMenu *_emoticonMenu;
}
- (id) initWithTranscript:(NSString *) filename;

- (IBAction) changeStyle:(id) sender;
- (void) setStyle:(JVStyle *) style withVariant:(NSString *) variant;
- (JVStyle *) style;

- (IBAction) changeStyleVariant:(id) sender;
- (void) setStyleVariant:(NSString *) variant;
- (NSString *) styleVariant;

- (IBAction) changeEmoticons:(id) sender;
- (void) setEmoticons:(JVEmoticonSet *) emoticons;
- (JVEmoticonSet *) emoticons;

- (JVChatTranscript *) transcript;
- (void) jumpToMessage:(JVChatMessage *) message;

- (IBAction) close:(id) sender;
- (IBAction) activate:(id) sender;
@end

#pragma mark -

@interface NSObject (MVChatPluginLinkClickSupport)
- (BOOL) handleClickedLink:(NSURL *) url inView:(id <JVChatViewController>) view;
@end