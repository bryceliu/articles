### 加载程序

#### gdb {program}

```
agg1@sukhoi agg1/.www-docs/tutorial> gdb main
GNU gdb 4.18
Copyright 1998 Free Software Foundation, Inc.
GDB is free software, covered by the GNU General Public License, and you are
welcome to change it and/or distribute copies of it under certain conditions.
Type "show copying" to see the conditions.
There is absolutely no warranty for GDB.  Type "show warranty" for details.
This GDB was configured as "sparc-sun-solaris2.7"...
(gdb)
```cpp

### 运行

#### run

```
(gdb) run
Starting program: /home/cec/s/a/agg1/.www-docs/tutorial/main 
Creating Node, 1 are in existence right now
Creating Node, 2 are in existence right now
Creating Node, 3 are in existence right now
Creating Node, 4 are in existence right now
The fully created list is:
4
3
2
1

Now removing elements:
Creating Node, 5 are in existence right now
Destroying Node, 4 are in existence right now
4
3
2
1


Program received signal SIGSEGV, Segmentation fault.
Node<int>::next (this=0x0) at main.cc:28
28	  Node<T>* next () const { return next_; }
(gdb)
```cpp

### 查看运行栈

#### backtrace

```
(gdb) backtrace
#0  Node<int>::next (this=0x0) at main.cc:28
#1  0x2a16c in LinkedList<int>::remove (this=0x40160, 
    item_to_remove=@0xffbef014) at main.cc:77
#2  0x1ad10 in main (argc=1, argv=0xffbef0a4) at main.cc:111
(gdb)
```cpp

### 查看地址值

#### x {address}

```
(gdb) x 0xffbef014
0xffbef014:	0x00000001
(gdb)
```cpp

### 设置断点

#### break {break code or line}

```
(gdb) break LinkedList<int>::remove
Breakpoint 1 at 0x29fa0: file main.cc, line 52.
(gdb)
```cpp

### 设置断点条件

#### condition {breakpoint number} {condition}

```
(gdb) condition 1 item_to_remove==1
(gdb)
```cpp

### 单步调试

#### 单步step，跳出函数next

```
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y

Starting program: /home/cec/s/a/agg1/.www-docs/tutorial/main 
Creating Node, 1 are in existence right now
Creating Node, 2 are in existence right now
Creating Node, 3 are in existence right now
Creating Node, 4 are in existence right now
The fully created list is:
4
3
2
1

Now removing elements:
Creating Node, 5 are in existence right now
Destroying Node, 4 are in existence right now
4
3
2
1


Breakpoint 1, LinkedList<int>::remove (this=0x40160, 
    item_to_remove=@0xffbef014) at main.cc:52
52	    Node<T> *marker = head_;
(gdb) step
53	    Node<T> *temp = 0;  // temp points to one behind as we iterate
(gdb) 
55	    while (marker != 0) {
(gdb) 
56	      if (marker->value() == item_to_remove) {
(gdb) 
Node<int>::value (this=0x401b0) at main.cc:30
30	  const T& value () const { return value_; }
(gdb) 
LinkedList<int>::remove (this=0x40160, item_to_remove=@0xffbef014)
    at main.cc:75
75	      marker = 0;  // reset the marker
(gdb) 
76	      temp = marker;
(gdb) 
77	      marker = marker->next();
(gdb) 
Node<int>::next (this=0x0) at main.cc:28
28	  Node<T>* next () const { return next_; }
(gdb) 

Program received signal SIGSEGV, Segmentation fault.
Node<int>::next (this=0x0) at main.cc:28
28	  Node<T>* next () const { return next_; }
(gdb)
```cpp
