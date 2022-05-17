#ifndef VFS_H
#define VFS_H

/*
 *  HERE I CREATE A struct THAT I CAN THEN COMBINE WITH kmalloc() TO START CREATING FILES. THESE FILES ARE VIRTUAL FILES, BUT
 *  THEN THEY CAN BE DUMPED INTO STORAGE-TYPE MEMORY DEVICES. WHAT I MEAN BY A VIRTUAL FILE SYSTEM, IS THAT THE FILE SYSTEM
 *  IS STORED CURRENTLY IN THE RAM. IT IS NO LONGER A VIRTUAL FILE ONCE IT IS DUMPED INTO A STORAGE DEVICE. WHEN IT IS LOADED
 *  BACK INTO RAM, IT IS VIRTUAL MEMORY AGAIN.
 */
typedef struct fs_node
{
  char name[128];
  uint8_t flags;
} fs_node_t;

#endif