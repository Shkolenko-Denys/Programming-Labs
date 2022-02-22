import datetime

import mysql.connector
from sqlalchemy import create_engine
from sqlalchemy.sql import text

import config


class WeatherDB:
    """Class Weather describes working with database."""

    def __init__(self, town: str):
        if not isinstance(town, str):
            raise TypeError("town must be a string")
        if not town:
            raise ValueError("town is empty")

        self.software_academy = mysql.connector.connect(
            host=config.library_db_host,
            user=config.library_db_user,
            password=config.library_db_password)

        self.engine = create_engine(
            f"{config.library_db_dialect}+{config.library_db_driver}://"
            f"{config.library_db_user}:{config.library_db_password}@"
            f"{config.library_db_host}/{config.library_db_name}")
        self.connection = self.engine.connect()

        sql_query = text(f"SELECT count(*) "
                         f"FROM information_schema.TABLES "
                         f"WHERE (TABLE_SCHEMA = '{config.library_db_name}') "
                         f"AND (TABLE_NAME = '{town}')")
        count = self.connection.execute(sql_query).fetchone()[0]
        if not count:
            raise ValueError("the town not supported")

        self.__town = town

    @property
    def town(self):
        return self.__town

    def add(self, year: int, month: int, day: int, time: datetime.time,
            temperature: int, direction: str, speed: int, weather_code: str,
            clouds: int, visibility: float, pressure: int, cloud_base: int):

        date_time = datetime.datetime(year, month, day, time.hour, time.minute)

        sql_query = text(
            f"INSERT {self.town}"
            f"(datetime, temperature, direction, speed, weather_code, "
            f"clouds, visibility, pressure, cloud_base) "
            f"VALUES "
            f"('{date_time}', {temperature}, '{direction}', {speed}, "
            f"'{weather_code}', {clouds}, {visibility}, {pressure}, "
            f"{cloud_base})")
        self.connection.execute(sql_query)
