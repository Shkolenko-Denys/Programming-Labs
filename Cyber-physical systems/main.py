from weather_excel_class import WeatherExcel
from weather_db_class import WeatherDB


if __name__ == "__main__":

    year = 2012
    month = 5
    method = "linear"
    town = "kyiv"

    weather_obj = WeatherExcel(
        year=year,
        month=month,
        input_path=f"input/{town}/{year}-{month}.xlsx",
        save_path=f"output/{town}",
        table_head_path="json/table_head.json",
        comments_path="json/comments.json",
        directions_path="json/directions.json",
        direction_numbers_path="json/direction_numbers.json",
        months_path="json/months.json")

    weather_obj.update_head("ukr")
    weather_obj.update_comments("ukr")
    weather_obj.update_temperature(method)
    weather_obj.update_speed(method)
    weather_obj.update_direction(method)
    weather_obj.update_weather_code()
    weather_obj.update_clouds(method)
    weather_obj.update_visibility(method)
    weather_obj.update_pressure(method)
    weather_obj.update_cloud_base(method)

    ws = weather_obj.ws

    weather_town = WeatherDB(town)

    for row in ws.iter_rows(min_row=2, max_row=weather_obj.rows,
                            min_col=1, max_col=10, values_only=True):
        weather_town.add(year, month, *row)
