//from Dao
比如，删除vector里的5
不能这样写
for(auto it = vec.begin(); it != vec.end(); it++)
{
     if(*it == 5) 
          vec.erase(it);
}
erase it后 it已经无效了
再it++要出错了

should:
for(auto it = vec.begin(); it != vec.end(); )
{
     if(*it == 5) 
         it = vec.erase(it);
    else
        ++it；
}
