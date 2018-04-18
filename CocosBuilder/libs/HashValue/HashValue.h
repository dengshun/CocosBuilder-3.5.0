//
//  HashValue.h
//  Hashing
//
//  Created by Matt Gallagher on 2009/07/06.
//  Copyright 2009 Matt Gallagher. All rights reserved.
//
//  Permission is given to use this source code file, free of charge, in any
//  project, commercial or otherwise, entirely at your risk, with the condition
//  that any redistribution (in part or whole) of source code must retain
//  this copyright and permission notice. Attribution in compiled projects is
//  appreciated but not required.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>

#define HASH_VALUE_STORAGE_SIZE 48

typedef struct
{
	char value[CC_SHA256_DIGEST_LENGTH];
} HashValueShaHash;

typedef struct
{
	char value[CC_MD5_DIGEST_LENGTH];
} HashValueMD5Hash;

typedef enum
{
	HASH_VALUE_MD5_TYPE,
	HASH_VALUE_SHA_TYPE
} HashValueType;

@interface HashValue : NSObject <NSCoding, NSCopying>
{
	unsigned char value[HASH_VALUE_STORAGE_SIZE];
	HashValueType type;
}

- (id)initWithBuffer:(const void *)buffer hashValueType:(HashValueType)aType;
- (id)initHashValueMD5HashWithBytes:(const void *)bytes length:(NSUInteger)length;
+ (HashValue *)md5HashWithData:(NSData *)data;
+ (HashValue *)md5HashWithString:(NSString*) string;
- (id)initSha256HashWithBytes:(const void *)bytes length:(NSUInteger)length;
+ (HashValue *)sha256HashWithData:(NSData *)data;

- (const void *)value;
- (HashValueType)type;

@end
