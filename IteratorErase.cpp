//from Dao
���磬ɾ��vector���5
��������д
for(auto it = vec.begin(); it != vec.end(); it++)
{
     if(*it == 5) 
          vec.erase(it);
}
erase it�� it�Ѿ���Ч��
��it++Ҫ������

should:
for(auto it = vec.begin(); it != vec.end(); )
{
     if(*it == 5) 
         it = vec.erase(it);
    else
        ++it��
}
