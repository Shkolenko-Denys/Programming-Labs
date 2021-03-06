/*-------------------------------------------------------------------<Header>-
 Name: ex_1.c
 Title: —
 Description: Нехай маємо код програми. 
 Розглянемо наступний виклик функції call: x = pr("Ho Ho Ho!").
 Напишіть повну версію програми та дайте відповідь або реалізуйте
 наступні задачі:
 A. Що виведе ця функція?
 B. Якого типу буде «х»?
 C. Яке значення матиме «х»?
 D. Що означає вираз «*--pc»? І як він відрізняється від виразу «--*pc»?
 E. Що виведеться якщо вираз «*--pc» буде замінено на вираз«*pc--»?
 F. Для чого або чому використовується два цикли while?
 G. Що трапиться у випадку, якщо pr() надійде з порожнім (нульовим) рядком
 замість аргументу?
 H. Що потрібно зробити у виклику функції для того, щоб pr() могла
 використовуватись так, як показано?
 -------------------------------------------------------------------</Header>-*/

#include <stdio.h>

char* pr(char* const str);

int main(void) {
    char* x; // x - pointer to char
    fputs(" Output: ", stdout); /* fputs() - stay on this line, no '\n';
    printf(" Output: ") - will give the same result, but
    puts(" Output: ") - automatically '\n' in the end */
    x = pr("Ho Ho Ho!"); /* x gets the address of the first character in the string */
    printf("\n x = %p\n", x); // print this address
    return 0;
}

char* pr(char* const str) { // constant pointer to char
    /* the char value, what this pointer points, can be changed.
    But we can't change the value of the pointer, it can't point to another char */
    char* pc; // pointer to char, will be changed
    pc = str; // now pc have address of first char in str
    while (*pc) { // while *pc != '\0'
        putchar(*pc++); /* *pc++ is treated as *(pc++).
        pc will be changed after the first use */
    }
    do {
        putchar(*--pc); /* *--pc is treated as *(--pc).
        pc will be changed before the first use */
    } while (pc != str); /* (pc != str) it's the same with (pc - str),
    but time of logical operations ==, !=, ||, && much less than
    the time of additive operations +, - */
    return pc; // here we can use just pc, without ()
}

/*
Запитання A:
Те, що саме виведе ця функція, можна подивитись на скриншоті. 

Запитання B:
Оскільки функція повертає адресу на базовий тип char, то х буде
вказівником на цей же тип даних, тобто х містить адресу.

Запитання C:
На скриншоті ми бачимо, якого саме значення набуває х

Запитання D:
Вираз “*--pc” можна переписати як “*(--pc)”. pc – це вказівник на
деякий символ, на початку в нього записано адресу першого символа строки, яку ми
передали у функцію. Далі використовуємо префіксний декремент, щоб зменшити pc на
одиницю, тобто повернутись на одну позицію вліво у строкі. Префіксний – щоб
зменшити значення pc, і тут же його використати, уже змінене. Тобто зменшуємо на
одиницю до використання (“одиницю” тобто на одну позицію в пам’яті). Далі
оператор розіменування, тобто звертаємось уже до значення, що знаходиться за
адресою. Основна ціль такого використання – це рухатись справа наліво по строкі,
і брати символи для друку. Вираз “--*pc” означає спочатку розіменовуємо pc,
отримаємо значення символа, що знаходиться за цією адресою, а далі знову
префіксний декремент. Віднімання буде проходити за таблицею ASCII, тобто
знайдеться символ, що має код на одиницю менший, він і буде надрукований.
Код “\0” це 0, тому адресу х ми не побачимо, а виведено буде лише
Output: Ho Ho Ho!

Запитання E:
Output: Ho Ho Ho! !oH oH o
x = 0040506E
Оскільки пріоритет -- більше, ніж оператор *, то “*pc--” теж саме, що “*(pc--)”,
а тому різниця лише в тому, коли буде декрементуватись pc до використання чи
після. Саме тому ми бачимо простір між ! !, там надрукований “\0”, а останньої
букви “H” не вистачає, бо pc дійшов до кінця строки швидше, ніж надрукувався
останній символ(цикл завершився).

Запитання F:
Два цикли використовується тому, що потрібно пройти строку зліва
направо, а потім справа наліво. При цьому треба використати різні параметри
циклу, саме тому ця дія розбита на два цикли.

Запитання G:
Перший цикл пропуститься, він не спрацює, а далі буде друкуватися
все, що тільки знайдеться за такою “некоректною” адресою, ми вийдемо за межі
масиву вліво.

Запитання H:
Тут варто використати char * const pnt – сталий вказівник на тип char.
Це означає, що оголошена змінна є постійним вказівником, що вказує на тип char.
Фактично це означає, що вказівник не повинен вказувати на будь-яку іншу адресу.
Кваліфікатор const не впливає на значення char в цьому випадку, тому значення,
що зберігається за адресою, може змінюватися.
*/