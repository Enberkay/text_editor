# text_editor

โครงสร้างโปรเจกต์สำหรับ Text Editor ขนาดเล็ก  
จัดระเบียบโค้ดให้เข้าใจง่าย พร้อมรองรับการขยายฟีเจอร์ในอนาคต

```
text_editor/
│
├── include/
│   ├── Editor.hpp          # คลาสหลัก Editor
│   ├── Command.hpp         # คำสั่งแต่ละแบบ เช่น InsertCommand, DeleteCommand
│
├── src/
│   ├── main.cpp            # จุดเริ่มโปรแกรม
│   ├── Editor.cpp
│   ├── Command.cpp
│
├── Makefile                # สำหรับ build
└── README.md               # อธิบายโปรเจกต์
```

## วิธี build

ใช้คำสั่งนี้ใน terminal:

```
mingw32-make clean
mingw32-make
```

---
