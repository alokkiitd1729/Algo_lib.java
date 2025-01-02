// #############################  Set ####################################################
   //[]- capture clause
    auto cmp = [](int a, int b) { return a > b; }; 
    set<int, decltype(cmp)> s(cmp);

// #############################  Multiset ####################################################
    auto cmp = [](int a, int b) { return a > b; }; 
    multiset<int, decltype(cmp)> s(cmp);

// #############################  Vector ####################################################
   auto cmp = [](int a, int b) { return a > b; }; 
   vector<int> v = {10, 30, 20, 50, 40};
   sort(v.begin(),v.end(),cmp);

// #############################  array ####################################################
   auto cmp = [](int a, int b) { return a > b; }; 
   int v[] = {10, 30, 20, 50, 40};
   sort(v,v+size(v),cmp);

// #############################  priority_queue ####################################################
   auto cmp = [](int a, int b) { return a > b; }; 
   priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
   // declared type, containers 
