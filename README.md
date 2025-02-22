# 🖥️ Operating Systems Course Notes

**Course Code**: CMP 232 | **Credit Hours**: 3-1-2 | [**Syllabus**](#syllabus-table)  


[![PRs Welcome](https://img.shields.io/badge/PRs-Welcome-brightgreen.svg)](https://github.com/KushalPrasadJoshi/operating-systems/pulls)
![Status](https://img.shields.io/badge/Status-Active-brightgreen)

A structured repository for **Pokhara University's Operating Systems** (CMP 232). Contains theory, code examples, practical labs, and project work to help students master Computer Graphics from basics to advanced concepts. This work is an independent effort by **Kushal Prasad Joshi**, inspired by the curriculum of **Pokhara University**, and is intended to support students in their academic journey. While based on the university's course structure, this work is not officially affiliated with or endorsed by **Pokhara University**.

---

## Syllabus Table

<table border="5">
    <thead>
        <tr>
            <th style="width: 30%;">Specific Objectives</th>
            <th style="width: 70%;">Contents</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>
                <ul>
                    <li>Familiarize with basic concepts of Operating systems, and its architecture.</li>
                    <li>Understanding the successive evolution of operating system.</li>
                </ul>
            </td>
            <td>
                <a href="/theory/01-introduction/README.md">Unit 1: Introduction</a><br>
                &emsp;<a href="/theory/01-introduction/README.md#11-concept-function">1.1 Concept and function of operating systems</a><br>
                &emsp;<a href="/theory/01-introduction/README.md#12-os-functionality">1.2 Operating systems concept and functionality</a><br>
                &emsp;&emsp;<a href="/theory/01-introduction/README.md#121-components">Processes, Files, System Calls, The Shell</a><br>
                &emsp;<a href="/theory/01-introduction/README.md#13-os-structure">1.3 Operating System Structure</a><br>
                &emsp;&emsp;<a href="/theory/01-introduction/README.md#131-structure-types">Monolithic, Layered, Virtual Machines, Client-server, Microkernel, Exokernel</a><br>
                &emsp;<a href="/theory/01-introduction/README.md#14-evolution">1.4 Types and Evolution of Operating Systems</a>
            </td>
        </tr>
        <tr>
            <td>
                <ul>
                    <li>Familiarize with Task, Process and threads.</li>
                    <li>Implement resource allocation techniques.</li>
                    <li>Understand mutual exclusion for resource utilization.</li>
                </ul>
            </td>
            <td>
                <a href="/theory/02-processes-threads/README.md">Unit 2: Processes and Threads</a><br>
                &emsp;<a href="/theory/02-processes-threads/README.md#21-process">2.1 Process</a><br>
                &emsp;&emsp;<a href="/theory/02-processes-threads/README.md#211-definition-states">Definition, states, transition diagram</a><br>
                &emsp;&emsp;<a href="/theory/02-processes-threads/README.md#212-pcb">Process Control Block (PCB)</a><br>
                &emsp;&emsp;<a href="/theory/02-processes-threads/README.md#213-concurrency">Concurrent and Parallel processes</a><br>
                &emsp;<a href="/theory/02-processes-threads/README.md#22-ipc-sync">2.2 Interprocess Communication and Synchronization</a><br>
                &emsp;&emsp;<a href="/theory/02-processes-threads/README.md#221-mutual-exclusion">Race Condition, Critical Regions, Mutual Exclusion (Dekker’s, Peterson’s algorithms)</a><br>
                &emsp;&emsp;<a href="/theory/02-processes-threads/README.md#222-sync-tools">Semaphore, Monitors, Bounded Buffer, Message Passing</a><br>
                &emsp;&emsp;<a href="/theory/02-processes-threads/README.md#223-ipc-problems">Classical IPC Problems (Dining Philosophers, Readers-Writers, Sleeping Barber)</a><br>
                &emsp;<a href="/theory/02-processes-threads/README.md#23-scheduling">2.3 Process Scheduling</a><br>
                &emsp;&emsp;<a href="/theory/02-processes-threads/README.md#231-algorithms">Scheduling Algorithms (FCFS, SJF, Round-Robin, Priority)</a><br>
                &emsp;<a href="/theory/02-processes-threads/README.md#24-threads">2.4 Threads</a><br>
                &emsp;&emsp;<a href="/theory/02-processes-threads/README.md#241-models">Thread Models (Many-to-One, One-to-One, Many-to-Many)</a><br>
                &emsp;&emsp;<a href="/theory/02-processes-threads/README.md#242-thread-types">User Space vs Kernel Space Threads</a>
            </td>
        </tr>
        <tr>
            <td>
                <ul>
                    <li>Conceptualize the role and working procedure of memory.</li>
                    <li>Familiarize with virtual memory management.</li>
                    <li>Understand page replacement algorithms.</li>
                </ul>
            </td>
            <td>
                <a href="/theory/03-memory-management/README.md">Unit 3: Memory Management</a><br>
                &emsp;<a href="/theory/03-memory-management/README.md#31-storage-org">3.1 Storage Organization and Memory Hierarchy</a><br>
                &emsp;<a href="/theory/03-memory-management/README.md#32-allocation">3.2 Contiguous vs Non-Contiguous Allocation</a><br>
                &emsp;<a href="/theory/03-memory-management/README.md#33-fragmentation">3.3 Fragmentation (Internal/External)</a><br>
                &emsp;<a href="/theory/03-memory-management/README.md#34-paging">3.4 Paging and Page Tables</a><br>
                &emsp;&emsp;<a href="/theory/03-memory-management/README.md#341-page-tables">Hierarchical, Hashed, Inverted Page Tables</a><br>
                &emsp;<a href="/theory/03-memory-management/README.md#35-virtual-memory">3.5 Virtual Memory and Demand Paging</a><br>
                &emsp;<a href="/theory/03-memory-management/README.md#36-page-replacement">3.6 Page Replacement Algorithms (FIFO, LRU, Optimal, Clock)</a><br>
                &emsp;<a href="/theory/03-memory-management/README.md#37-segmentation">3.7 Segmentation and Compaction</a>
            </td>
        </tr>
        <tr>
            <td>
                <ul>
                    <li>Conceptualization of Kernel and its role in system software.</li>
                </ul>
            </td>
            <td>
                <a href="/theory/04-kernel/README.md">Unit 4: Kernel</a><br>
                &emsp;<a href="/theory/04-kernel/README.md#41-kernel-architecture">4.1 Kernel Architecture and Types</a><br>
                &emsp;<a href="/theory/04-kernel/README.md#42-context-switching">4.2 Context Switching (Kernel vs User Mode)</a>
            </td>
        </tr>
        <tr>
            <td>
                <ul>
                    <li>Understand the role of input/output devices.</li>
                    <li>Understand different approaches for optimal output.</li>
                </ul>
            </td>
            <td>
                <a href="/theory/05-io-management/README.md">Unit 5: Input/Output Management</a><br>
                &emsp;<a href="/theory/05-io-management/README.md#51-io-hardware">5.1 I/O Hardware (Device Controllers, DMA)</a><br>
                &emsp;<a href="/theory/05-io-management/README.md#52-io-software">5.2 I/O Software (Interrupt Handlers, Device Drivers)</a><br>
                &emsp;<a href="/theory/05-io-management/README.md#53-deadlocks">5.3 Deadlock Handling (Banker’s Algorithm, Resource Allocation Graph)</a><br>
                &emsp;<a href="/theory/05-io-management/README.md#54-raid-ram">5.4 RAID and RAM Disks</a>
            </td>
        </tr>
        <tr>
            <td>
                <ul>
                    <li>Understand the file and filing mechanism.</li>
                    <li>Familiarize with directory management techniques.</li>
                </ul>
            </td>
            <td>
                <a href="/theory/06-file-systems/README.md">Unit 6: File Systems</a><br>
                &emsp;<a href="/theory/06-file-systems/README.md#61-file-org">6.1 File Organization (Blocking, Buffering, File Attributes)</a><br>
                &emsp;<a href="/theory/06-file-systems/README.md#62-directories">6.2 Directory Management (Hierarchical, Path Names)</a><br>
                &emsp;<a href="/theory/06-file-systems/README.md#63-access-methods">6.3 File Access Methods (Sequential, Direct)</a><br>
                &emsp;<a href="/theory/06-file-systems/README.md#64-implementation">6.4 File System Implementation (Contiguous, Linked Allocation)</a>
            </td>
        </tr>
        <tr>
            <td>
                <ul>
                    <li>Familiarize with current trends of operating systems.</li>
                </ul>
            </td>
            <td>
                <a href="/theory/07-new-trends/README.md">Unit 7: New Trends in Operating Systems</a><br>
                &emsp;<a href="/theory/07-new-trends/README.md#71-realtime-distributed">7.1 Real-Time and Distributed OS</a><br>
                &emsp;<a href="/theory/07-new-trends/README.md#72-cloud-mobile">7.2 Cloud and Mobile OS</a><br>
                &emsp;<a href="/theory/07-new-trends/README.md#73-security-bottlenecks">7.3 Security Issues and Memory Bottlenecks</a>
            </td>
        </tr>
    </tbody>
</table>

---

## 📜 License
**All Rights Reserved**  
This repository is for personal, educational, and non-commercial use only. Modifying, distributing, or using this content for commercial purposes is strictly prohibited without explicit permission. Please refer to the [LICENSE](LICENSE) file for further details.  

---

**Happy Reading!** 🎉