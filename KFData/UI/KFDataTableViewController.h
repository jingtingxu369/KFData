//
//  KFDataTableViewController.h
//  KFData
//
//  Created by Kyle Fuller on 08/11/2012.
//  Copyright (c) 2012-2013 Kyle Fuller. All rights reserved.
//

#import <Availability.h>

#if __IPHONE_OS_VERSION_MIN_REQUIRED
#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@class KFObjectManager;
@class KFDataTableViewDataSource;

/** KFDataTableViewController is a generic controller base uses
 KFDataTableViewDataSource as a data source. Providing helper methods for
 ease of use.
*/

@interface KFDataTableViewController : UITableViewController

@property (nonatomic, strong, readonly) KFDataTableViewDataSource *dataSource;

- (void)setManagedObjectContext:(NSManagedObjectContext *)managedObjectContext
                   fetchRequest:(NSFetchRequest *)fetchRequest
             sectionNameKeyPath:(NSString *)sectionNameKeyPath
                      cacheName:(NSString *)cacheName;

- (void)setObjectManager:(KFObjectManager *)objectManager
      sectionNameKeyPath:(NSString *)sectionNameKeyPath
               cacheName:(NSString *)cacheName;

/** Executes the fetch request on the store to get objects and load them into the collection view.
 @returns YES if successful or NO (and an error) if a problem occurred.
 An error is returned if the fetch request specified doesn't include a sort descriptor that uses sectionNameKeyPath.'
 */
- (BOOL)performFetch:(NSError **)error;

- (UITableViewCell *)tableView:(UITableView *)tableView cellForManagedObject:(NSManagedObject *)managedObject atIndexPath:(NSIndexPath *)indexPath;

@end

#endif
