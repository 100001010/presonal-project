// -*- C++ -*-
//===---------------------------- set -------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_SET
#define _LIBCPP_SET

/*

    set synopsis

namespace std
{

template <class Key, class Compare = less<Key>,
          class Allocator = allocator<Key>>
class set
{
public:
    // types:
    typedef Key                                      key_type;
    typedef key_type                                 value_type;
    typedef Compare                                  key_compare;
    typedef key_compare                              value_compare;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;

    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
    typedef unspecified                              node_type;               // C++17
    typedef INSERT_RETURN_TYPE<iterator, node_type>  insert_return_type;      // C++17

    // construct/copy/destroy:
    set()
        noexcept(
            is_nothrow_default_constructible<allocator_type>::value &&
            is_nothrow_default_constructible<key_compare>::value &&
            is_nothrow_copy_constructible<key_compare>::value);

    explicit set(const value_compare& comp);

    set(const value_compare& comp, const allocator_type& a);

    template <class InputIterator>
        set(InputIterator first, InputIterator last,
            const value_compare& comp = value_compare());

    template <class InputIterator>
        set(InputIterator first, InputIterator last, const value_compare& comp,
            const allocator_type& a);

    set(const set& s);

    set(set&& s)
        noexcept(
            is_nothrow_move_constructible<allocator_type>::value &&
            is_nothrow_move_constructible<key_compare>::value);

    explicit set(const allocator_type& a);

    set(const set& s, const allocator_type& a);

    set(set&& s, const allocator_type& a);

    set(initializer_list<value_type> il, const value_compare& comp = value_compare());

    set(initializer_list<value_type> il, const value_compare& comp,
        const allocator_type& a);
        
    template <class InputIterator>
        set(InputIterator first, InputIterator last, const allocator_type& a)
            : set(first, last, Compare(), a) {}  // C++14
    set(initializer_list<value_type> il, const allocator_type& a)
        : set(il, Compare(), a) {}  // C++14
    ~set();

    set& operator=(const set& s);
    set& operator=(set&& s)
        noexcept(
            allocator_type::propagate_on_container_move_assignment::value &&
            is_nothrow_move_assignable<allocator_type>::value &&
            is_nothrow_move_assignable<key_compare>::value);
    set& operator=(initializer_list<value_type> il);

    // iterators:
          iterator begin() noexcept;
    const_iterator begin() const noexcept;
          iterator end() noexcept;
    const_iterator end()   const noexcept;

          reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
          reverse_iterator rend() noexcept;
    const_reverse_iterator rend()   const noexcept;

    const_iterator         cbegin()  const noexcept;
    const_iterator         cend()    const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend()   const noexcept;

    // capacity:
    bool      empty()    const noexcept;
    size_type size()     const noexcept;
    size_type max_size() const noexcept;

    // modifiers:
    template <class... Args>
        pair<iterator, bool> emplace(Args&&... args);
    template <class... Args>
        iterator emplace_hint(const_iterator position, Args&&... args);
    pair<iterator,bool> insert(const value_type& v);
    pair<iterator,bool> insert(value_type&& v);
    iterator insert(const_iterator position, const value_type& v);
    iterator insert(const_iterator position, value_type&& v);
    template <class InputIterator>
        void insert(InputIterator first, InputIterator last);
    void insert(initializer_list<value_type> il);

    node_type extract(const_iterator position);                                       // C++17
    node_type extract(const key_type& x);                                             // C++17
    insert_return_type insert(node_type&& nh);                                        // C++17
    iterator insert(const_iterator hint, node_type&& nh);                             // C++17

    iterator  erase(const_iterator position);
    iterator  erase(iterator position);  // C++14
    size_type erase(const key_type& k);
    iterator  erase(const_iterator first, const_iterator last);
    void clear() noexcept;

    template<class C2>
      void merge(set<Key, C2, Allocator>& source);         // C++17
    template<class C2>
      void merge(set<Key, C2, Allocator>&& source);        // C++17
    template<class C2>
      void merge(multiset<Key, C2, Allocator>& source);    // C++17
    template<class C2>
      void merge(multiset<Key, C2, Allocator>&& source);   // C++17

    void swap(set& s)
        noexcept(
            __is_nothrow_swappable<key_compare>::value &&
            (!allocator_type::propagate_on_container_swap::value ||
             __is_nothrow_swappable<allocator_type>::value));

    // observers:
    allocator_type get_allocator() const noexcept;
    key_compare    key_comp()      const;
    value_compare  value_comp()    const;

    // set operations:
          iterator find(const key_type& k);
    const_iterator find(const key_type& k) const;
    template<typename K>
        iterator find(const K& x);
    template<typename K>
        const_iterator find(const K& x) const;  // C++14

    template<typename K>
        size_type count(const K& x) const;        // C++14
    size_type      count(const key_type& k) const;

    bool           contains(const key_type& x) const;  // C++20
    template<class K> bool contains(const K& x) const; // C++20

          iterator lower_bound(const key_type& k);
    const_iterator lower_bound(const key_type& k) const;
    template<typename K>
        iterator lower_bound(const K& x);              // C++14
    template<typename K>
        const_iterator lower_bound(const K& x) const;  // C++14

          iterator upper_bound(const key_type& k);
    const_iterator upper_bound(const key_type& k) const;
    template<typename K>
        iterator upper_bound(const K& x);              // C++14
    template<typename K>
        const_iterator upper_bound(const K& x) const;  // C++14
    pair<iterator,iterator>             equal_range(const key_type& k);
    pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
    template<typename K>
        pair<iterator,iterator>             equal_range(const K& x);        // C++14
    template<typename K>
        pair<const_iterator,const_iterator> equal_range(const K& x) const;  // C++14
};

template <class Key, class Compare, class Allocator>
bool
operator==(const set<Key, Compare, Allocator>& x,
           const set<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool
operator< (const set<Key, Compare, Allocator>& x,
           const set<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool
operator!=(const set<Key, Compare, Allocator>& x,
           const set<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool
operator> (const set<Key, Compare, Allocator>& x,
           const set<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool
operator>=(const set<Key, Compare, Allocator>& x,
           const set<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool
operator<=(const set<Key, Compare, Allocator>& x,
           const set<Key, Compare, Allocator>& y);

// specialized algorithms:
template <class Key, class Compare, class Allocator>
void
swap(set<Key, Compare, Allocator>& x, set<Key, Compare, Allocator>& y)
    noexcept(noexcept(x.swap(y)));

template <class Key, class Compare, class Allocator, class Predicate>
typename set<Key, Compare, Allocator>::size_type
erase_if(set<Key, Compare, Allocator>& c, Predicate pred);  // C++20

template <class Key, class Compare = less<Key>,
          class Allocator = allocator<Key>>
class multiset
{
public:
    // types:
    typedef Key                                      key_type;
    typedef key_type                                 value_type;
    typedef Compare                                  key_compare;
    typedef key_compare                              value_compare;
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;

    typedef implementation-defined                   iterator;
    typedef implementation-defined                   const_iterator;
    typedef std::reverse_iterator<iterator>          reverse_iterator;
    typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
    typedef unspecified                              node_type;               // C++17

    // construct/copy/destroy:
    multiset()
        noexcept(
            is_nothrow_default_constructible<allocator_type>::value &&
            is_nothrow_default_constructible<key_compare>::value &&
            is_nothrow_copy_constructible<key_compare>::value);
    explicit multiset(const value_compare& comp);
    multiset(const value_compare& comp, const allocator_type& a);
    template <class InputIterator>
        multiset(InputIterator first, InputIterator last,
                 const value_compare& comp = value_compare());
    template <class InputIterator>
        multiset(InputIterator first, InputIterator last,
                 const value_compare& comp, const allocator_type& a);
    multiset(const multiset& s);
    multiset(multiset&& s)
        noexcept(
            is_nothrow_move_constructible<allocator_type>::value &&
            is_nothrow_move_constructible<key_compare>::value);
    explicit multiset(const allocator_type& a);
    multiset(const multiset& s, const allocator_type& a);
    multiset(multiset&& s, const allocator_type& a);
    multiset(initializer_list<value_type> il, const value_compare& comp = value_compare());
    multiset(initializer_list<value_type> il, const value_compare& comp,
             const allocator_type& a);
    template <class InputIterator>
        multiset(InputIterator first, InputIterator last, const allocator_type& a)
            : set(first, last, Compare(), a) {}  // C++14
    multiset(initializer_list<value_type> il, const allocator_type& a)
        : set(il, Compare(), a) {}  // C++14
    ~multiset();

    multiset& operator=(const multiset& s);
    multiset& operator=(multiset&& s)
        noexcept(
            allocator_type::propagate_on_container_move_assignment::value &&
            is_nothrow_move_assignable<allocator_type>::value &&
            is_nothrow_move_assignable<key_compare>::value);
    multiset& operator=(initializer_list<value_type> il);

    // iterators:
          iterator begin() noexcept;
    const_iterator begin() const noexcept;
          iterator end() noexcept;
    const_iterator end()   const noexcept;

          reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
          reverse_iterator rend() noexcept;
    const_reverse_iterator rend()   const noexcept;

    const_iterator         cbegin()  const noexcept;
    const_iterator         cend()    const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend()   const noexcept;

    // capacity:
    bool      empty()    const noexcept;
    size_type size()     const noexcept;
    size_type max_size() const noexcept;

    // modifiers:
    template <class... Args>
        iterator emplace(Args&&... args);
    template <class... Args>
        iterator emplace_hint(const_iterator position, Args&&... args);
    iterator insert(const value_type& v);
    iterator insert(value_type&& v);
    iterator insert(const_iterator position, const value_type& v);
    iterator insert(const_iterator position, value_type&& v);
    template <class InputIterator>
        void insert(InputIterator first, InputIterator last);
    void insert(initializer_list<value_type> il);

    node_type extract(const_iterator position);                                       // C++17
    node_type extract(const key_type& x);                                             // C++17
    iterator insert(node_type&& nh);                                                  // C++17
    iterator insert(const_iterator hint, node_type&& nh);                             // C++17

    iterator  erase(const_iterator position);
    iterator  erase(iterator position);  // C++14
    size_type erase(const key_type& k);
    iterator  erase(const_iterator first, const_iterator last);
    void clear() noexcept;

    template<class C2>
      void merge(multiset<Key, C2, Allocator>& source);    // C++17
    template<class C2>
      void merge(multiset<Key, C2, Allocator>&& source);   // C++17
    template<class C2>
      void merge(set<Key, C2, Allocator>& source);         // C++17
    template<class C2>
      void merge(set<Key, C2, Allocator>&& source);        // C++17

    void swap(multiset& s)
        noexcept(
            __is_nothrow_swappable<key_compare>::value &&
            (!allocator_type::propagate_on_container_swap::value ||
             __is_nothrow_swappable<allocator_type>::value));

    // observers:
    allocator_type get_allocator() const noexcept;
    key_compare    key_comp()      const;
    value_compare  value_comp()    const;

    // set operations:
          iterator find(const key_type& k);
    const_iterator find(const key_type& k) const;
    template<typename K>
        iterator find(const K& x);
    template<typename K>
        const_iterator find(const K& x) const;  // C++14

    template<typename K>
        size_type count(const K& x) const;      // C++14
    size_type      count(const key_type& k) const;

    bool           contains(const key_type& x) const;  // C++20
    template<class K> bool contains(const K& x) const; // C++20

          iterator lower_bound(const key_type& k);
    const_iterator lower_bound(const key_type& k) const;
    template<typename K>
        iterator lower_bound(const K& x);              // C++14
    template<typename K>
        const_iterator lower_bound(const K& x) const;  // C++14

          iterator upper_bound(const key_type& k);
    const_iterator upper_bound(const key_type& k) const;
    template<typename K>
        iterator upper_bound(const K& x);              // C++14
    template<typename K>
        const_iterator upper_bound(const K& x) const;  // C++14

    pair<iterator,iterator>             equal_range(const key_type& k);
    pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
    template<typename K>
        pair<iterator,iterator>             equal_range(const K& x);        // C++14
    template<typename K>
        pair<const_iterator,const_iterator> equal_range(const K& x) const;  // C++14
};

template <class Key, class Compare, class Allocator>
bool
operator==(const multiset<Key, Compare, Allocator>& x,
           const multiset<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool
operator< (const multiset<Key, Compare, Allocator>& x,
           const multiset<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool
operator!=(const multiset<Key, Compare, Allocator>& x,
           const multiset<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool
operator> (const multiset<Key, Compare, Allocator>& x,
           const multiset<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool
operator>=(const multiset<Key, Compare, Allocator>& x,
           const multiset<Key, Compare, Allocator>& y);

template <class Key, class Compare, class Allocator>
bool
operator<=(const multiset<Key, Compare, Allocator>& x,
           const multiset<Key, Compare, Allocator>& y);

// specialized algorithms:
template <class Key, class Compare, class Allocator>
void
swap(multiset<Key, Compare, Allocator>& x, multiset<Key, Compare, Allocator>& y)
    noexcept(noexcept(x.swap(y)));

template <class Key, class Compare, class Allocator, class Predicate>
typename multiset<Key, Compare, Allocator>::size_type
erase_if(multiset<Key, Compare, Allocator>& c, Predicate pred);  // C++20

}  // std

*/

#include <__config>
#include <__debug>
#include <__functional/is_transparent.h>
#include <__node_handle>
#include <__tree>
#include <__utility/forward.h>
#include <compare>
#include <functional>
#include <initializer_list>
#include <iterator> // __libcpp_erase_if_container
#include <version>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#pragma GCC system_header
#endif

_LIBCPP_BEGIN_NAMESPACE_STD

template <class _Key, class _Compare, class _Allocator>
class multiset;

template <class _Key, class _Compare = less<_Key>,
          class _Allocator = allocator<_Key> >
class _LIBCPP_TEMPLATE_VIS set
{
public:
    // types:
    typedef _Key                                     key_type;
    typedef key_type                                 value_type;
    typedef _Compare                                 key_compare;
    typedef key_compare                              value_compare;
    typedef __identity_t<_Allocator>                 allocator_type;
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;

    static_assert((is_same<typename allocator_type::value_type, value_type>::value),
                  "Allocator::value_type must be same type as value_type");

private:
    typedef __tree<value_type, value_compare, allocator_type> __base;
    typedef allocator_traits<allocator_type>                  __alloc_traits;
    typedef typename __base::__node_holder                    __node_holder;

    __base __tree_;

public:
    typedef typename __base::pointer               pointer;
    typedef typename __base::const_pointer         const_pointer;
    typedef typename __base::size_type             size_type;
    typedef typename __base::difference_type       difference_type;
    typedef typename __base::const_iterator        iterator;
    typedef typename __base::const_iterator        const_iterator;
    typedef _VSTD::reverse_iterator<iterator>       reverse_iterator;
    typedef _VSTD::reverse_iterator<const_iterator> const_reverse_iterator;

#if _LIBCPP_STD_VER > 14
    typedef __set_node_handle<typename __base::__node, allocator_type> node_type;
    typedef __insert_return_type<iterator, node_type> insert_return_type;
#endif

    template <class _Key2, class _Compare2, class _Alloc2>
        friend class _LIBCPP_TEMPLATE_VIS set;
    template <class _Key2, class _Compare2, class _Alloc2>
        friend class _LIBCPP_TEMPLATE_VIS multiset;

    _LIBCPP_INLINE_VISIBILITY
    set()
        _NOEXCEPT_(
            is_nothrow_default_constructible<allocator_type>::value &&
            is_nothrow_default_constructible<key_compare>::value &&
            is_nothrow_copy_constructible<key_compare>::value)
        : __tree_(value_compare()) {}

    _LIBCPP_INLINE_VISIBILITY
    explicit set(const value_compare& __comp)
        _NOEXCEPT_(
            is_nothrow_default_constructible<allocator_type>::value &&
            is_nothrow_copy_constructible<key_compare>::value)
        : __tree_(__comp) {}

    _LIBCPP_INLINE_VISIBILITY
    explicit set(const value_compare& __comp, const allocator_type& __a)
        : __tree_(__comp, __a) {}
    template <class _InputIterator>
        _LIBCPP_INLINE_VISIBILITY
        set(_InputIterator __f, _InputIterator __l,
            const value_compare& __comp = value_compare())
        : __tree_(__comp)
        {
            insert(__f, __l);
        }

    template <class _InputIterator>
        _LIBCPP_INLINE_VISIBILITY
        set(_InputIterator __f, _InputIterator __l, const value_compare& __comp,
            const allocator_type& __a)
        : __tree_(__comp, __a)
        {
            insert(__f, __l);
        }

#if _LIBCPP_STD_VER > 11
        template <class _InputIterator>
        _LIBCPP_INLINE_VISIBILITY
        set(_InputIterator __f, _InputIterator __l, const allocator_type& __a)
            : set(__f, __l, key_compare(), __a) {}
#endif

    _LIBCPP_INLINE_VISIBILITY
    set(const set& __s)
        : __tree_(__s.__tree_)
        {
            insert(__s.begin(), __s.end());
        }

    _LIBCPP_INLINE_VISIBILITY
    set& operator=(const set& __s)
        {
            __tree_ = __s.__tree_;
            return *this;
        }

#ifndef _LIBCPP_CXX03_LANG
    _LIBCPP_INLINE_VISIBILITY
    set(set&& __s)
        _NOEXCEPT_(is_nothrow_move_constructible<__base>::value)
        : __tree_(_VSTD::move(__s.__tree_)) {}
#endif // _LIBCPP_CXX03_LANG

    _LIBCPP_INLINE_VISIBILITY
    explicit set(const allocator_type& __a)
        : __tree_(__a) {}

    _LIBCPP_INLINE_VISIBILITY
    set(const set& __s, const allocator_type& __a)
        : __tree_(__s.__tree_.value_comp(), __a)
        {
            insert(__s.begin(), __s.end());
        }

#ifndef _LIBCPP_CXX03_LANG
    set(set&& __s, const allocator_type& __a);

    _LIBCPP_INLINE_VISIBILITY
    set(initializer_list<value_type> __il, const value_compare& __comp = value_compare())
        : __tree_(__comp)
        {
            insert(__il.begin(), __il.end());
        }

    _LIBCPP_INLINE_VISIBILITY
    set(initializer_list<value_type> __il, const value_compare& __comp,
        const allocator_type& __a)
        : __tree_(__comp, __a)
        {
            insert(__il.begin(), __il.end());
        }

#if _LIBCPP_STD_VER > 11
    _LIBCPP_INLINE_VISIBILITY
    set(initializer_list<value_type> __il, const allocator_type& __a)
        : set(__il, key_compare(), __a) {}
#endif

    _LIBCPP_INLINE_VISIBILITY
    set& operator=(initializer_list<value_type> __il)
        {
            __tree_.__assign_unique(__il.begin(), __il.end());
            return *this;
        }

    _LIBCPP_INLINE_VISIBILITY
    set& operator=(set&& __s)
        _NOEXCEPT_(is_nothrow_move_assignable<__base>::value)
        {
            __tree_ = _VSTD::move(__s.__tree_);
            return *this;
        }
#endif // _LIBCPP_CXX03_LANG

    _LIBCPP_INLINE_VISIBILITY
    ~set() {
        static_assert(sizeof(__diagnose_non_const_comparator<_Key, _Compare>()), "");
    }

    _LIBCPP_INLINE_VISIBILITY
          iterator begin() _NOEXCEPT       {return __tree_.begin();}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator begin() const _NOEXCEPT {return __tree_.begin();}
    _LIBCPP_INLINE_VISIBILITY
          iterator end() _NOEXCEPT         {return __tree_.end();}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator end()   const _NOEXCEPT {return __tree_.end();}

    _LIBCPP_INLINE_VISIBILITY
          reverse_iterator rbegin() _NOEXCEPT
            {return reverse_iterator(end());}
    _LIBCPP_INLINE_VISIBILITY
    const_reverse_iterator rbegin() const _NOEXCEPT
        {return const_reverse_iterator(end());}
    _LIBCPP_INLINE_VISIBILITY
          reverse_iterator rend() _NOEXCEPT
            {return reverse_iterator(begin());}
    _LIBCPP_INLINE_VISIBILITY
    const_reverse_iterator rend() const _NOEXCEPT
        {return const_reverse_iterator(begin());}

    _LIBCPP_INLINE_VISIBILITY
    const_iterator cbegin()  const _NOEXCEPT {return begin();}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator cend() const _NOEXCEPT {return end();}
    _LIBCPP_INLINE_VISIBILITY
    const_reverse_iterator crbegin() const _NOEXCEPT {return rbegin();}
    _LIBCPP_INLINE_VISIBILITY
    const_reverse_iterator crend() const _NOEXCEPT {return rend();}

    _LIBCPP_NODISCARD_AFTER_CXX17 _LIBCPP_INLINE_VISIBILITY
    bool empty() const _NOEXCEPT {return __tree_.size() == 0;}
    _LIBCPP_INLINE_VISIBILITY
    size_type size() const _NOEXCEPT {return __tree_.size();}
    _LIBCPP_INLINE_VISIBILITY
    size_type max_size() const _NOEXCEPT {return __tree_.max_size();}

    // modifiers:
#ifndef _LIBCPP_CXX03_LANG
    template <class... _Args>
        _LIBCPP_INLINE_VISIBILITY
        pair<iterator, bool> emplace(_Args&&... __args)
            {return __tree_.__emplace_unique(_VSTD::forward<_Args>(__args)...);}
    template <class... _Args>
        _LIBCPP_INLINE_VISIBILITY
        iterator emplace_hint(const_iterator __p, _Args&&... __args)
            {return __tree_.__emplace_hint_unique(__p, _VSTD::forward<_Args>(__args)...);}
#endif // _LIBCPP_CXX03_LANG

    _LIBCPP_INLINE_VISIBILITY
    pair<iterator,bool> insert(const value_type& __v)
        {return __tree_.__insert_unique(__v);}
    _LIBCPP_INLINE_VISIBILITY
    iterator insert(const_iterator __p, const value_type& __v)
        {return __tree_.__insert_unique(__p, __v);}

    template <class _InputIterator>
        _LIBCPP_INLINE_VISIBILITY
        void insert(_InputIterator __f, _InputIterator __l)
        {
            for (const_iterator __e = cend(); __f != __l; ++__f)
                __tree_.__insert_unique(__e, *__f);
        }

#ifndef _LIBCPP_CXX03_LANG
    _LIBCPP_INLINE_VISIBILITY
    pair<iterator,bool> insert(value_type&& __v)
        {return __tree_.__insert_unique(_VSTD::move(__v));}

    _LIBCPP_INLINE_VISIBILITY
    iterator insert(const_iterator __p, value_type&& __v)
        {return __tree_.__insert_unique(__p, _VSTD::move(__v));}

    _LIBCPP_INLINE_VISIBILITY
    void insert(initializer_list<value_type> __il)
        {insert(__il.begin(), __il.end());}
#endif // _LIBCPP_CXX03_LANG

    _LIBCPP_INLINE_VISIBILITY
    iterator  erase(const_iterator __p) {return __tree_.erase(__p);}
    _LIBCPP_INLINE_VISIBILITY
    size_type erase(const key_type& __k)
        {return __tree_.__erase_unique(__k);}
    _LIBCPP_INLINE_VISIBILITY
    iterator  erase(const_iterator __f, const_iterator __l)
        {return __tree_.erase(__f, __l);}
    _LIBCPP_INLINE_VISIBILITY
    void clear() _NOEXCEPT {__tree_.clear();}

#if _LIBCPP_STD_VER > 14
    _LIBCPP_INLINE_VISIBILITY
    insert_return_type insert(node_type&& __nh)
    {
        _LIBCPP_ASSERT(__nh.empty() || __nh.get_allocator() == get_allocator(),
            "node_type with incompatible allocator passed to set::insert()");
        return __tree_.template __node_handle_insert_unique<
            node_type, insert_return_type>(_VSTD::move(__nh));
    }
    _LIBCPP_INLINE_VISIBILITY
    iterator insert(const_iterator __hint, node_type&& __nh)
    {
        _LIBCPP_ASSERT(__nh.empty() || __nh.get_allocator() == get_allocator(),
            "node_type with incompatible allocator passed to set::insert()");
        return __tree_.template __node_handle_insert_unique<node_type>(
            __hint, _VSTD::move(__nh));
    }
    _LIBCPP_INLINE_VISIBILITY
    node_type extract(key_type const& __key)
    {
        return __tree_.template __node_handle_extract<node_type>(__key);
    }
    _LIBCPP_INLINE_VISIBILITY
    node_type extract(const_iterator __it)
    {
        return __tree_.template __node_handle_extract<node_type>(__it);
    }
    template <class _Compare2>
    _LIBCPP_INLINE_VISIBILITY
    void merge(set<key_type, _Compare2, allocator_type>& __source)
    {
        _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(),
                       "merging container with incompatible allocator");
        __tree_.__node_handle_merge_unique(__source.__tree_);
    }
    template <class _Compare2>
    _LIBCPP_INLINE_VISIBILITY
    void merge(set<key_type, _Compare2, allocator_type>&& __source)
    {
        _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(),
                       "merging container with incompatible allocator");
        __tree_.__node_handle_merge_unique(__source.__tree_);
    }
    template <class _Compare2>
    _LIBCPP_INLINE_VISIBILITY
    void merge(multiset<key_type, _Compare2, allocator_type>& __source)
    {
        _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(),
                       "merging container with incompatible allocator");
        __tree_.__node_handle_merge_unique(__source.__tree_);
    }
    template <class _Compare2>
    _LIBCPP_INLINE_VISIBILITY
    void merge(multiset<key_type, _Compare2, allocator_type>&& __source)
    {
        _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(),
                       "merging container with incompatible allocator");
        __tree_.__node_handle_merge_unique(__source.__tree_);
    }
#endif

    _LIBCPP_INLINE_VISIBILITY
    void swap(set& __s) _NOEXCEPT_(__is_nothrow_swappable<__base>::value)
        {__tree_.swap(__s.__tree_);}

    _LIBCPP_INLINE_VISIBILITY
    allocator_type get_allocator() const _NOEXCEPT {return __tree_.__alloc();}
    _LIBCPP_INLINE_VISIBILITY
    key_compare    key_comp()      const {return __tree_.value_comp();}
    _LIBCPP_INLINE_VISIBILITY
    value_compare  value_comp()    const {return __tree_.value_comp();}

    // set operations:
    _LIBCPP_INLINE_VISIBILITY
    iterator find(const key_type& __k)             {return __tree_.find(__k);}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator find(const key_type& __k) const {return __tree_.find(__k);}
#if _LIBCPP_STD_VER > 11
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,iterator>::type
    find(const _K2& __k)                           {return __tree_.find(__k);}
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,const_iterator>::type
    find(const _K2& __k) const                     {return __tree_.find(__k);}
#endif

    _LIBCPP_INLINE_VISIBILITY
    size_type      count(const key_type& __k) const
        {return __tree_.__count_unique(__k);}
#if _LIBCPP_STD_VER > 11
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,size_type>::type
    count(const _K2& __k) const                    {return __tree_.__count_multi(__k);}
#endif

#if _LIBCPP_STD_VER > 17
    _LIBCPP_INLINE_VISIBILITY
    bool contains(const key_type& __k) const {return find(__k) != end();}
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value, bool>::type
    contains(const _K2& __k) const { return find(__k) != end(); }
#endif // _LIBCPP_STD_VER > 17

    _LIBCPP_INLINE_VISIBILITY
    iterator lower_bound(const key_type& __k)
        {return __tree_.lower_bound(__k);}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator lower_bound(const key_type& __k) const
        {return __tree_.lower_bound(__k);}
#if _LIBCPP_STD_VER > 11
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,iterator>::type
    lower_bound(const _K2& __k)       {return __tree_.lower_bound(__k);}

    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,const_iterator>::type
    lower_bound(const _K2& __k) const {return __tree_.lower_bound(__k);}
#endif

    _LIBCPP_INLINE_VISIBILITY
    iterator upper_bound(const key_type& __k)
        {return __tree_.upper_bound(__k);}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator upper_bound(const key_type& __k) const
        {return __tree_.upper_bound(__k);}
#if _LIBCPP_STD_VER > 11
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,iterator>::type
    upper_bound(const _K2& __k)       {return __tree_.upper_bound(__k);}
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,const_iterator>::type
    upper_bound(const _K2& __k) const {return __tree_.upper_bound(__k);}
#endif

    _LIBCPP_INLINE_VISIBILITY
    pair<iterator,iterator> equal_range(const key_type& __k)
        {return __tree_.__equal_range_unique(__k);}
    _LIBCPP_INLINE_VISIBILITY
    pair<const_iterator,const_iterator> equal_range(const key_type& __k) const
        {return __tree_.__equal_range_unique(__k);}
#if _LIBCPP_STD_VER > 11
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,pair<iterator,iterator>>::type
    equal_range(const _K2& __k)       {return __tree_.__equal_range_multi(__k);}
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,pair<const_iterator,const_iterator>>::type
    equal_range(const _K2& __k) const {return __tree_.__equal_range_multi(__k);}
#endif
};

#if _LIBCPP_STD_VER >= 17
template<class _InputIterator,
         class _Compare = less<__iter_value_type<_InputIterator>>,
         class _Allocator = allocator<__iter_value_type<_InputIterator>>,
         class = enable_if_t<__is_allocator<_Allocator>::value, void>,
         class = enable_if_t<!__is_allocator<_Compare>::value, void>>
set(_InputIterator, _InputIterator, _Compare = _Compare(), _Allocator = _Allocator())
  -> set<__iter_value_type<_InputIterator>, _Compare, _Allocator>;

template<class _Key, class _Compare = less<_Key>,
         class _Allocator = allocator<_Key>,
         class = enable_if_t<__is_allocator<_Allocator>::value, void>,
         class = enable_if_t<!__is_allocator<_Compare>::value, void>>
set(initializer_list<_Key>, _Compare = _Compare(), _Allocator = _Allocator())
  -> set<_Key, _Compare, _Allocator>;

template<class _InputIterator, class _Allocator,
         class = enable_if_t<__is_allocator<_Allocator>::value, void>>
set(_InputIterator, _InputIterator, _Allocator)
  -> set<__iter_value_type<_InputIterator>,
         less<__iter_value_type<_InputIterator>>, _Allocator>;

template<class _Key, class _Allocator,
         class = enable_if_t<__is_allocator<_Allocator>::value, void>>
set(initializer_list<_Key>, _Allocator)
  -> set<_Key, less<_Key>, _Allocator>;
#endif

#ifndef _LIBCPP_CXX03_LANG

template <class _Key, class _Compare, class _Allocator>
set<_Key, _Compare, _Allocator>::set(set&& __s, const allocator_type& __a)
    : __tree_(_VSTD::move(__s.__tree_), __a)
{
    if (__a != __s.get_allocator())
    {
        const_iterator __e = cend();
        while (!__s.empty())
            insert(__e, _VSTD::move(__s.__tree_.remove(__s.begin())->__value_));
    }
}

#endif // _LIBCPP_CXX03_LANG

template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator==(const set<_Key, _Compare, _Allocator>& __x,
           const set<_Key, _Compare, _Allocator>& __y)
{
    return __x.size() == __y.size() && _VSTD::equal(__x.begin(), __x.end(), __y.begin());
}

template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator< (const set<_Key, _Compare, _Allocator>& __x,
           const set<_Key, _Compare, _Allocator>& __y)
{
    return _VSTD::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
}

template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator!=(const set<_Key, _Compare, _Allocator>& __x,
           const set<_Key, _Compare, _Allocator>& __y)
{
    return !(__x == __y);
}

template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator> (const set<_Key, _Compare, _Allocator>& __x,
           const set<_Key, _Compare, _Allocator>& __y)
{
    return __y < __x;
}

template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator>=(const set<_Key, _Compare, _Allocator>& __x,
           const set<_Key, _Compare, _Allocator>& __y)
{
    return !(__x < __y);
}

template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator<=(const set<_Key, _Compare, _Allocator>& __x,
           const set<_Key, _Compare, _Allocator>& __y)
{
    return !(__y < __x);
}

// specialized algorithms:
template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
void
swap(set<_Key, _Compare, _Allocator>& __x,
     set<_Key, _Compare, _Allocator>& __y)
    _NOEXCEPT_(_NOEXCEPT_(__x.swap(__y)))
{
    __x.swap(__y);
}

#if _LIBCPP_STD_VER > 17
template <class _Key, class _Compare, class _Allocator, class _Predicate>
inline _LIBCPP_INLINE_VISIBILITY
    typename set<_Key, _Compare, _Allocator>::size_type
    erase_if(set<_Key, _Compare, _Allocator>& __c, _Predicate __pred) {
  return _VSTD::__libcpp_erase_if_container(__c, __pred);
}
#endif

template <class _Key, class _Compare = less<_Key>,
          class _Allocator = allocator<_Key> >
class _LIBCPP_TEMPLATE_VIS multiset
{
public:
    // types:
    typedef _Key                                     key_type;
    typedef key_type                                 value_type;
    typedef _Compare                                 key_compare;
    typedef key_compare                              value_compare;
    typedef __identity_t<_Allocator>                 allocator_type;
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;

    static_assert((is_same<typename allocator_type::value_type, value_type>::value),
                  "Allocator::value_type must be same type as value_type");

private:
    typedef __tree<value_type, value_compare, allocator_type> __base;
    typedef allocator_traits<allocator_type>                  __alloc_traits;
    typedef typename __base::__node_holder                    __node_holder;

    __base __tree_;

public:
    typedef typename __base::pointer               pointer;
    typedef typename __base::const_pointer         const_pointer;
    typedef typename __base::size_type             size_type;
    typedef typename __base::difference_type       difference_type;
    typedef typename __base::const_iterator        iterator;
    typedef typename __base::const_iterator        const_iterator;
    typedef _VSTD::reverse_iterator<iterator>       reverse_iterator;
    typedef _VSTD::reverse_iterator<const_iterator> const_reverse_iterator;

#if _LIBCPP_STD_VER > 14
    typedef __set_node_handle<typename __base::__node, allocator_type> node_type;
#endif

    template <class _Key2, class _Compare2, class _Alloc2>
        friend class _LIBCPP_TEMPLATE_VIS set;
    template <class _Key2, class _Compare2, class _Alloc2>
        friend class _LIBCPP_TEMPLATE_VIS multiset;

    // construct/copy/destroy:
    _LIBCPP_INLINE_VISIBILITY
    multiset()
        _NOEXCEPT_(
            is_nothrow_default_constructible<allocator_type>::value &&
            is_nothrow_default_constructible<key_compare>::value &&
            is_nothrow_copy_constructible<key_compare>::value)
        : __tree_(value_compare()) {}

    _LIBCPP_INLINE_VISIBILITY
    explicit multiset(const value_compare& __comp)
        _NOEXCEPT_(
            is_nothrow_default_constructible<allocator_type>::value &&
            is_nothrow_copy_constructible<key_compare>::value)
        : __tree_(__comp) {}

    _LIBCPP_INLINE_VISIBILITY
    explicit multiset(const value_compare& __comp, const allocator_type& __a)
        : __tree_(__comp, __a) {}
    template <class _InputIterator>
        _LIBCPP_INLINE_VISIBILITY
        multiset(_InputIterator __f, _InputIterator __l,
                 const value_compare& __comp = value_compare())
        : __tree_(__comp)
        {
            insert(__f, __l);
        }

#if _LIBCPP_STD_VER > 11
        template <class _InputIterator>
        _LIBCPP_INLINE_VISIBILITY
        multiset(_InputIterator __f, _InputIterator __l, const allocator_type& __a)
            : multiset(__f, __l, key_compare(), __a) {}
#endif

    template <class _InputIterator>
        _LIBCPP_INLINE_VISIBILITY
        multiset(_InputIterator __f, _InputIterator __l,
                 const value_compare& __comp, const allocator_type& __a)
        : __tree_(__comp, __a)
        {
            insert(__f, __l);
        }

    _LIBCPP_INLINE_VISIBILITY
    multiset(const multiset& __s)
        : __tree_(__s.__tree_.value_comp(),
          __alloc_traits::select_on_container_copy_construction(__s.__tree_.__alloc()))
        {
            insert(__s.begin(), __s.end());
        }

    _LIBCPP_INLINE_VISIBILITY
    multiset& operator=(const multiset& __s)
        {
            __tree_ = __s.__tree_;
            return *this;
        }

#ifndef _LIBCPP_CXX03_LANG
    _LIBCPP_INLINE_VISIBILITY
    multiset(multiset&& __s)
        _NOEXCEPT_(is_nothrow_move_constructible<__base>::value)
        : __tree_(_VSTD::move(__s.__tree_)) {}

    multiset(multiset&& __s, const allocator_type& __a);
#endif // _LIBCPP_CXX03_LANG
    _LIBCPP_INLINE_VISIBILITY
    explicit multiset(const allocator_type& __a)
        : __tree_(__a) {}
    _LIBCPP_INLINE_VISIBILITY
    multiset(const multiset& __s, const allocator_type& __a)
        : __tree_(__s.__tree_.value_comp(), __a)
        {
            insert(__s.begin(), __s.end());
        }

#ifndef _LIBCPP_CXX03_LANG
    _LIBCPP_INLINE_VISIBILITY
    multiset(initializer_list<value_type> __il, const value_compare& __comp = value_compare())
        : __tree_(__comp)
        {
            insert(__il.begin(), __il.end());
        }

    _LIBCPP_INLINE_VISIBILITY
    multiset(initializer_list<value_type> __il, const value_compare& __comp,
        const allocator_type& __a)
        : __tree_(__comp, __a)
        {
            insert(__il.begin(), __il.end());
        }

#if _LIBCPP_STD_VER > 11
    _LIBCPP_INLINE_VISIBILITY
    multiset(initializer_list<value_type> __il, const allocator_type& __a)
        : multiset(__il, key_compare(), __a) {}
#endif

    _LIBCPP_INLINE_VISIBILITY
    multiset& operator=(initializer_list<value_type> __il)
        {
            __tree_.__assign_multi(__il.begin(), __il.end());
            return *this;
        }

    _LIBCPP_INLINE_VISIBILITY
    multiset& operator=(multiset&& __s)
        _NOEXCEPT_(is_nothrow_move_assignable<__base>::value)
        {
            __tree_ = _VSTD::move(__s.__tree_);
            return *this;
        }
#endif // _LIBCPP_CXX03_LANG

    _LIBCPP_INLINE_VISIBILITY
    ~multiset() {
        static_assert(sizeof(__diagnose_non_const_comparator<_Key, _Compare>()), "");
    }

    _LIBCPP_INLINE_VISIBILITY
          iterator begin() _NOEXCEPT       {return __tree_.begin();}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator begin() const _NOEXCEPT {return __tree_.begin();}
    _LIBCPP_INLINE_VISIBILITY
          iterator end() _NOEXCEPT         {return __tree_.end();}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator end()   const _NOEXCEPT {return __tree_.end();}

    _LIBCPP_INLINE_VISIBILITY
          reverse_iterator rbegin() _NOEXCEPT
            {return reverse_iterator(end());}
    _LIBCPP_INLINE_VISIBILITY
    const_reverse_iterator rbegin() const _NOEXCEPT
        {return const_reverse_iterator(end());}
    _LIBCPP_INLINE_VISIBILITY
          reverse_iterator rend() _NOEXCEPT
            {return       reverse_iterator(begin());}
    _LIBCPP_INLINE_VISIBILITY
    const_reverse_iterator rend() const _NOEXCEPT
        {return const_reverse_iterator(begin());}

    _LIBCPP_INLINE_VISIBILITY
    const_iterator cbegin()  const _NOEXCEPT {return begin();}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator cend() const _NOEXCEPT {return end();}
    _LIBCPP_INLINE_VISIBILITY
    const_reverse_iterator crbegin() const _NOEXCEPT {return rbegin();}
    _LIBCPP_INLINE_VISIBILITY
    const_reverse_iterator crend() const _NOEXCEPT {return rend();}

    _LIBCPP_NODISCARD_AFTER_CXX17 _LIBCPP_INLINE_VISIBILITY
    bool empty() const _NOEXCEPT {return __tree_.size() == 0;}
    _LIBCPP_INLINE_VISIBILITY
    size_type size() const _NOEXCEPT {return __tree_.size();}
    _LIBCPP_INLINE_VISIBILITY
    size_type max_size() const _NOEXCEPT {return __tree_.max_size();}

    // modifiers:
#ifndef _LIBCPP_CXX03_LANG
    template <class... _Args>
        _LIBCPP_INLINE_VISIBILITY
        iterator emplace(_Args&&... __args)
            {return __tree_.__emplace_multi(_VSTD::forward<_Args>(__args)...);}
    template <class... _Args>
        _LIBCPP_INLINE_VISIBILITY
        iterator emplace_hint(const_iterator __p, _Args&&... __args)
            {return __tree_.__emplace_hint_multi(__p, _VSTD::forward<_Args>(__args)...);}
#endif // _LIBCPP_CXX03_LANG

    _LIBCPP_INLINE_VISIBILITY
    iterator insert(const value_type& __v)
        {return __tree_.__insert_multi(__v);}
    _LIBCPP_INLINE_VISIBILITY
    iterator insert(const_iterator __p, const value_type& __v)
        {return __tree_.__insert_multi(__p, __v);}

    template <class _InputIterator>
        _LIBCPP_INLINE_VISIBILITY
        void insert(_InputIterator __f, _InputIterator __l)
        {
            for (const_iterator __e = cend(); __f != __l; ++__f)
                __tree_.__insert_multi(__e, *__f);
        }

#ifndef _LIBCPP_CXX03_LANG
    _LIBCPP_INLINE_VISIBILITY
    iterator insert(value_type&& __v)
        {return __tree_.__insert_multi(_VSTD::move(__v));}

    _LIBCPP_INLINE_VISIBILITY
    iterator insert(const_iterator __p, value_type&& __v)
        {return __tree_.__insert_multi(__p, _VSTD::move(__v));}

    _LIBCPP_INLINE_VISIBILITY
    void insert(initializer_list<value_type> __il)
        {insert(__il.begin(), __il.end());}
#endif // _LIBCPP_CXX03_LANG

    _LIBCPP_INLINE_VISIBILITY
    iterator  erase(const_iterator __p) {return __tree_.erase(__p);}
    _LIBCPP_INLINE_VISIBILITY
    size_type erase(const key_type& __k) {return __tree_.__erase_multi(__k);}
    _LIBCPP_INLINE_VISIBILITY
    iterator  erase(const_iterator __f, const_iterator __l)
        {return __tree_.erase(__f, __l);}
    _LIBCPP_INLINE_VISIBILITY
    void clear() _NOEXCEPT {__tree_.clear();}

#if _LIBCPP_STD_VER > 14
    _LIBCPP_INLINE_VISIBILITY
    iterator insert(node_type&& __nh)
    {
        _LIBCPP_ASSERT(__nh.empty() || __nh.get_allocator() == get_allocator(),
            "node_type with incompatible allocator passed to multiset::insert()");
        return __tree_.template __node_handle_insert_multi<node_type>(
            _VSTD::move(__nh));
    }
    _LIBCPP_INLINE_VISIBILITY
    iterator insert(const_iterator __hint, node_type&& __nh)
    {
        _LIBCPP_ASSERT(__nh.empty() || __nh.get_allocator() == get_allocator(),
            "node_type with incompatible allocator passed to multiset::insert()");
        return __tree_.template __node_handle_insert_multi<node_type>(
            __hint, _VSTD::move(__nh));
    }
    _LIBCPP_INLINE_VISIBILITY
    node_type extract(key_type const& __key)
    {
        return __tree_.template __node_handle_extract<node_type>(__key);
    }
    _LIBCPP_INLINE_VISIBILITY
    node_type extract(const_iterator __it)
    {
        return __tree_.template __node_handle_extract<node_type>(__it);
    }
    template <class _Compare2>
    _LIBCPP_INLINE_VISIBILITY
    void merge(multiset<key_type, _Compare2, allocator_type>& __source)
    {
        _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(),
                       "merging container with incompatible allocator");
        __tree_.__node_handle_merge_multi(__source.__tree_);
    }
    template <class _Compare2>
    _LIBCPP_INLINE_VISIBILITY
    void merge(multiset<key_type, _Compare2, allocator_type>&& __source)
    {
        _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(),
                       "merging container with incompatible allocator");
        __tree_.__node_handle_merge_multi(__source.__tree_);
    }
    template <class _Compare2>
    _LIBCPP_INLINE_VISIBILITY
    void merge(set<key_type, _Compare2, allocator_type>& __source)
    {
        _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(),
                       "merging container with incompatible allocator");
        __tree_.__node_handle_merge_multi(__source.__tree_);
    }
    template <class _Compare2>
    _LIBCPP_INLINE_VISIBILITY
    void merge(set<key_type, _Compare2, allocator_type>&& __source)
    {
        _LIBCPP_ASSERT(__source.get_allocator() == get_allocator(),
                       "merging container with incompatible allocator");
        __tree_.__node_handle_merge_multi(__source.__tree_);
    }
#endif

    _LIBCPP_INLINE_VISIBILITY
    void swap(multiset& __s)
        _NOEXCEPT_(__is_nothrow_swappable<__base>::value)
        {__tree_.swap(__s.__tree_);}

    _LIBCPP_INLINE_VISIBILITY
    allocator_type get_allocator() const _NOEXCEPT {return __tree_.__alloc();}
    _LIBCPP_INLINE_VISIBILITY
    key_compare    key_comp()      const {return __tree_.value_comp();}
    _LIBCPP_INLINE_VISIBILITY
    value_compare  value_comp()    const {return __tree_.value_comp();}

    // set operations:
    _LIBCPP_INLINE_VISIBILITY
    iterator find(const key_type& __k)             {return __tree_.find(__k);}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator find(const key_type& __k) const {return __tree_.find(__k);}
#if _LIBCPP_STD_VER > 11
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,iterator>::type
    find(const _K2& __k)                           {return __tree_.find(__k);}
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,const_iterator>::type
    find(const _K2& __k) const                     {return __tree_.find(__k);}
#endif

    _LIBCPP_INLINE_VISIBILITY
    size_type      count(const key_type& __k) const
        {return __tree_.__count_multi(__k);}
#if _LIBCPP_STD_VER > 11
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,size_type>::type
    count(const _K2& __k) const            {return __tree_.__count_multi(__k);}
#endif

#if _LIBCPP_STD_VER > 17
    _LIBCPP_INLINE_VISIBILITY
    bool contains(const key_type& __k) const {return find(__k) != end();}
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value, bool>::type
    contains(const _K2& __k) const { return find(__k) != end(); }
#endif // _LIBCPP_STD_VER > 17

    _LIBCPP_INLINE_VISIBILITY
    iterator lower_bound(const key_type& __k)
        {return __tree_.lower_bound(__k);}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator lower_bound(const key_type& __k) const
            {return __tree_.lower_bound(__k);}
#if _LIBCPP_STD_VER > 11
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,iterator>::type
    lower_bound(const _K2& __k)       {return __tree_.lower_bound(__k);}

    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,const_iterator>::type
    lower_bound(const _K2& __k) const {return __tree_.lower_bound(__k);}
#endif

    _LIBCPP_INLINE_VISIBILITY
    iterator upper_bound(const key_type& __k)
            {return __tree_.upper_bound(__k);}
    _LIBCPP_INLINE_VISIBILITY
    const_iterator upper_bound(const key_type& __k) const
            {return __tree_.upper_bound(__k);}
#if _LIBCPP_STD_VER > 11
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,iterator>::type
    upper_bound(const _K2& __k)       {return __tree_.upper_bound(__k);}
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,const_iterator>::type
    upper_bound(const _K2& __k) const {return __tree_.upper_bound(__k);}
#endif

    _LIBCPP_INLINE_VISIBILITY
    pair<iterator,iterator>             equal_range(const key_type& __k)
            {return __tree_.__equal_range_multi(__k);}
    _LIBCPP_INLINE_VISIBILITY
    pair<const_iterator,const_iterator> equal_range(const key_type& __k) const
            {return __tree_.__equal_range_multi(__k);}
#if _LIBCPP_STD_VER > 11
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,pair<iterator,iterator>>::type
    equal_range(const _K2& __k)       {return __tree_.__equal_range_multi(__k);}
    template <typename _K2>
    _LIBCPP_INLINE_VISIBILITY
    typename enable_if<__is_transparent<_Compare, _K2>::value,pair<const_iterator,const_iterator>>::type
    equal_range(const _K2& __k) const {return __tree_.__equal_range_multi(__k);}
#endif
};

#if _LIBCPP_STD_VER >= 17
template<class _InputIterator,
         class _Compare = less<__iter_value_type<_InputIterator>>,
         class _Allocator = allocator<__iter_value_type<_InputIterator>>,
         class = enable_if_t<__is_allocator<_Allocator>::value, void>,
         class = enable_if_t<!__is_allocator<_Compare>::value, void>>
multiset(_InputIterator, _InputIterator, _Compare = _Compare(), _Allocator = _Allocator())
  -> multiset<__iter_value_type<_InputIterator>, _Compare, _Allocator>;

template<class _Key, class _Compare = less<_Key>,
         class _Allocator = allocator<_Key>,
         class = enable_if_t<__is_allocator<_Allocator>::value, void>,
         class = enable_if_t<!__is_allocator<_Compare>::value, void>>
multiset(initializer_list<_Key>, _Compare = _Compare(), _Allocator = _Allocator())
  -> multiset<_Key, _Compare, _Allocator>;

template<class _InputIterator, class _Allocator,
         class = enable_if_t<__is_allocator<_Allocator>::value, void>>
multiset(_InputIterator, _InputIterator, _Allocator)
  -> multiset<__iter_value_type<_InputIterator>,
         less<__iter_value_type<_InputIterator>>, _Allocator>;

template<class _Key, class _Allocator,
         class = enable_if_t<__is_allocator<_Allocator>::value, void>>
multiset(initializer_list<_Key>, _Allocator)
  -> multiset<_Key, less<_Key>, _Allocator>;
#endif

#ifndef _LIBCPP_CXX03_LANG

template <class _Key, class _Compare, class _Allocator>
multiset<_Key, _Compare, _Allocator>::multiset(multiset&& __s, const allocator_type& __a)
    : __tree_(_VSTD::move(__s.__tree_), __a)
{
    if (__a != __s.get_allocator())
    {
        const_iterator __e = cend();
        while (!__s.empty())
            insert(__e, _VSTD::move(__s.__tree_.remove(__s.begin())->__value_));
    }
}

#endif // _LIBCPP_CXX03_LANG

template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator==(const multiset<_Key, _Compare, _Allocator>& __x,
           const multiset<_Key, _Compare, _Allocator>& __y)
{
    return __x.size() == __y.size() && _VSTD::equal(__x.begin(), __x.end(), __y.begin());
}

template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator< (const multiset<_Key, _Compare, _Allocator>& __x,
           const multiset<_Key, _Compare, _Allocator>& __y)
{
    return _VSTD::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
}

template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator!=(const multiset<_Key, _Compare, _Allocator>& __x,
           const multiset<_Key, _Compare, _Allocator>& __y)
{
    return !(__x == __y);
}

template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator> (const multiset<_Key, _Compare, _Allocator>& __x,
           const multiset<_Key, _Compare, _Allocator>& __y)
{
    return __y < __x;
}

template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator>=(const multiset<_Key, _Compare, _Allocator>& __x,
           const multiset<_Key, _Compare, _Allocator>& __y)
{
    return !(__x < __y);
}

template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator<=(const multiset<_Key, _Compare, _Allocator>& __x,
           const multiset<_Key, _Compare, _Allocator>& __y)
{
    return !(__y < __x);
}

template <class _Key, class _Compare, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
void
swap(multiset<_Key, _Compare, _Allocator>& __x,
     multiset<_Key, _Compare, _Allocator>& __y)
    _NOEXCEPT_(_NOEXCEPT_(__x.swap(__y)))
{
    __x.swap(__y);
}

#if _LIBCPP_STD_VER > 17
template <class _Key, class _Compare, class _Allocator, class _Predicate>
inline _LIBCPP_INLINE_VISIBILITY
    typename multiset<_Key, _Compare, _Allocator>::size_type
    erase_if(multiset<_Key, _Compare, _Allocator>& __c, _Predicate __pred) {
  return _VSTD::__libcpp_erase_if_container(__c, __pred);
}
#endif

_LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP_SET
