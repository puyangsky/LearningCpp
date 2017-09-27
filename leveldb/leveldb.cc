#include <string.h>
#include <iostream>
#include <assert.h>
#include "third_party/leveldb/db.h"

using namespace std;

int main()
{
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());

    string key1 = "a";
    string key2 = "b";

    status = db->Put(leveldb::WriteOptions(), key1, "fuck");

    assert(status.ok());
    cout<<"insert into db, key:"<<key1<<endl;
    string value;
    status = db->Get(leveldb::ReadOptions(), key1, &value);
    assert(status.ok());
    cout<<"get value from db, " << value<<endl;
    status = db->Delete(leveldb::WriteOptions(), key1);

    assert(status.ok());
    cout<<"delete from db, key1:"<<key1<<endl;
 
    return 0;
}