import org.junit.jupiter.api.Test;

import java.util.HashSet;

import static org.junit.jupiter.api.Assertions.*;

class Task16Test2 {

    @Test
    void symmetricDiff() {
        HashSet<Integer> set1 = new HashSet<>(){{
            add(1);
            add(2);
            add(3);
            add(4);
            add(5);
        }};
        HashSet<Integer> set2 = new HashSet<>(){{
            add(2);
            add(3);
            add(5);
        }};

        HashSet<Integer> actual = Task16.symmetricDiff(set1, set2);
        HashSet<Integer> expected = new HashSet<>(){{
            add(1);
            add(4);
        }};

        assertEquals(expected, actual);
    }
}