# AntiVirus Project
# סיכום פרויקט: מערכת AntiVirus ב-C

## how to run:
make clean
make
valgrind --leak-check=full ./AntiVirus 
L
signatures-L
P                    // now we can see the viruses we have in db
S
infected             // the file we will inspect
D                   // what viruses has been detected
F                   // fixig the file
D                   // check that there are non
Q                   // exiting



##  מטרת הפרויקט (על מה הייתה העבודה)
פיתוח תוכנת אנטיוירוס בסיסית מבוססת חתימות (Signature-based). התוכנית קוראת חתימות של וירוסים מקובץ נתונים, טוענת אותן לזיכרון באמצעות רשימה מקושרת, וסורקת קבצים בינאריים חשודים. במידה ונמצאת התאמה לחתימה (באמצעות סריקה של הבאפר בשיטת "החלון הגולש"), התוכנית מנטרלת את הוירוס על ידי פתיחת הקובץ מחדש, ניווט למיקום המדויק, ודריסת הבית הראשון של הוירוס עם פקודת Assembly מסוג `RET` (`0xC3`), מה שמונע מהקוד הזדוני לרוץ.

##  מיומנויות וכלים (Skills)
* **תכנות Low-Level ב-C:** עבודה מעשית ומתקדמת עם מצביעים (Pointers), טיפוסי נתונים מדויקים (כמו `size_t` ו-`unsigned char`) ומבנים (Structs).
* **ניהול זיכרון דינמי ו-Valgrind:** הקצאה ושחרור זיכרון בצורה מבוקרת (`malloc` / `free`). שימוש בכלי Valgrind לאיתור שגיאות זיכרון עד להגעה למצב מושלם של אפס דליפות (Zero Memory Leaks).
* **עבודה עם קבצים בינאריים (Binary File I/O):** קריאה, כתיבה וניווט כירורגי בקבצים ברמת הבית (Byte) באמצעות `fread`, `fwrite` ו-`fseek` (שימוש במצבים `rb` ו-`r+b` לעריכה במקום).
* **מבני נתונים:** מימוש רשימה מקושרת (Singly Linked List) לניהול דינמי ויעיל של מאגר החתימות.
* **יסודות Reverse Engineering:** התערבות בקבצי הרצה, שימוש בעורכים בינאריים (`hexedit`), והזרקת קוד מכונה (Machine Code Injection).
* **קלט בטוח:** טיפול מוגן בקלט משתמש למניעת גלישת חוצץ (Buffer Overflow) באמצעות `fgets` ו-`sscanf`.