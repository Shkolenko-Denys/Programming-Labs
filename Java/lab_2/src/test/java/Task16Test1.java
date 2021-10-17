import org.junit.jupiter.api.Test;

import java.util.HashSet;

import static org.junit.jupiter.api.Assertions.*;

class Task16Test1 {

    @Test
    void symmetricDiff() {
        HashSet<Integer> set1 = new HashSet<>();
        HashSet<Integer> set2 = new HashSet<>();

        HashSet<Integer> actual = Task16.symmetricDiff(set1, set2);
        HashSet<Integer> expected = new HashSet<>();

        assertEquals(expected, actual);
    }
}