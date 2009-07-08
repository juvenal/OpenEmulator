
/**
 * OpenEmulator
 * Mac OS X Document Controller
 * (C) 2009 by Marc S. Ressl (mressl@umich.edu)
 * Released under the GPL
 *
 * Manages documents.
 */

#import <Cocoa/Cocoa.h>

#import "portaudio/include/portaudio.h"
#import "InspectorPanelController.h"

@interface DocumentController : NSDocumentController {
	NSUserDefaults *fDefaults;
	IBOutlet InspectorPanelController *fInspectorPanelController;

	NSArray *fileTypes;

	PaStream *portAudioStream;
	
	bool isNewDocumentWindowOpen;
	
	int disableMenuBarCount;
}

- (id)openUntitledDocumentFromTemplateURL:(NSURL *)templateURL error:(NSError **)outError;
- (id)makeUntitledDocumentFromTemplateURL:(NSURL *)templateURL error:(NSError **)outError;
- (void)noteNewDocumentWindowClosed;
- (void)disableMenuBar;
- (void)enableMenuBar;

@end