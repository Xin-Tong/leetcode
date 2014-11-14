//from Dao

//delete 5 from vector, we CAN NOT:
for(auto it = vec.begin(); it != vec.end(); it++)
{
     if(*it == 5) 
          vec.erase(it);
}

//after erasing it, it has no function.
//if we do it++, will bring errors
should:
for(auto it = vec.begin(); it != vec.end(); )
{
     if(*it == 5) 
         it = vec.erase(it);
    else
        ++it£»
}
