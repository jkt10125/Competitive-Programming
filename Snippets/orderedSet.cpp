/*
    ORDERED SET
    st.find_by_order(index) -> pointer to element of given index
    st.order_of_key(element) -> number of elements strictly less than that element
 */

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T = int>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T = int>
// using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// END

// NOTE find function of ordered multiset is not working properly
//      instead use ordered set and store {val, idx} to make each element different