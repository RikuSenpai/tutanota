//
//  TUTFileUtil.h
//  Tutanota plugin
//
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUTFileUtil : NSObject

- (instancetype)initWithViewController:(UIViewController *)viewController;

/* Definitions from the FileUtil.js interface. */
//- (void)openFileChooser:(CDVInvokedUrlCommand*)command;
//- (void)write:(CDVInvokedUrlCommand*)command;
//- (void)read:(CDVInvokedUrlCommand*)command;
- (void)openFileAtPath:(NSString * )filePath
			completion:(void (^ )(NSError * _Nullable))completion;

- (void) openFile:(NSString*) name fileData:(NSData*) fileData completion:(void(^)(NSError *  error))completion;

- (void)deleteFileAtPath:(NSString * )filePath
			  completion:(void (^ )(void))completion;

- (void)getNameForPath:(NSString * )filePath
			completion:(void (^ )(NSString * _Nullable name, NSError * _Nullable error))completion;

- (void)getMimeTypeForPath:(NSString * )filePath
				completion:(void (^ )(NSString * _Nullable mime, NSError * _Nullable  error))completion;

- (void)getSizeForPath:(NSString * )filePath
			completion:(void (^ )(NSNumber * _Nullable size, NSError * _Nullable errir))completion;

- (void)uploadFileAtPath:(NSString * )filePath
				   toUrl:(NSString * )urlString
			 withHeaders:(NSDictionary<NSString *, NSString *> * )headers
			  completion:(void (^ )(NSDictionary<NSString *, id> * _Nullable response, NSError * _Nullable error))completion;

- (void)downloadFileFromUrl:(NSString * )urlString
					forName:(NSString * )fileName
				withHeaders:(NSDictionary<NSString *, NSString *> * )headers
				 completion:(void (^ )(NSDictionary<NSString *, id> * _Nullable response, NSError * _Nullable error))completion;

- (void)clearFileData;


/** Helper functions for file access. */
+ (NSString*)getEncryptedFolder:(NSError **) error;
+ (NSString*)getDecryptedFolder:(NSError **) error;
+ (BOOL)fileExistsAtPath:(NSString *)path;
+ (NSURL*)urlFromPath:(NSString *)path;
+ (NSString*)pathFromUrl:(NSURL *)url;

@end

NS_ASSUME_NONNULL_END