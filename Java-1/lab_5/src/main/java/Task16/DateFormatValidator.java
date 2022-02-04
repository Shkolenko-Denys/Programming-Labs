package Task16;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;


public record DateFormatValidator(
        String dateFormat) implements DateValidator {

    @Override
    public boolean isValid(String dateStr) {
        DateFormat sdf = new SimpleDateFormat(this.dateFormat);
        sdf.setLenient(false);
        try {
            sdf.parse(dateStr);
        } catch (ParseException e) {
            return false;
        }
        return true;
    }
}
