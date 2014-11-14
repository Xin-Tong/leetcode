//from Dao

it++
iterator operator++£¨int£©
{
     iterator temp£¨*this£©£»
     inc();
     return temp;
}

++it
iterator& operator++£¨£©
{
     inc();
     return *this;
}
