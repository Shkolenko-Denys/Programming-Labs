import mysql.connector
from sqlalchemy import create_engine
from sqlalchemy.sql import text

import config
from classes.local_course import LocalCourse
from classes.offsite_course import OffsiteCourse


class SoftwareAcademy:
    """The class that describes the software academy.

    Working with the software academy database."""

    def __init__(self):
        self.software_academy = mysql.connector.connect(
            host=config.library_db_host,
            user=config.library_db_user,
            password=config.library_db_password)
        self.engine = create_engine(
            f"{config.library_db_dialect}+{config.library_db_driver}://"
            f"{config.library_db_user}:{config.library_db_password}@"
            f"{config.library_db_host}/{config.library_db_name}")
        self.connection = self.engine.connect()

    def get_local_courses_dict(self):
        sql_query = text("""SELECT * FROM local_courses""")
        local_courses_dicts = self.connection.execute(sql_query)\
            .mappings().all()
        return local_courses_dicts

    def get_offsite_courses_dict(self):
        sql_query = text("""SELECT * FROM offsite_courses""")
        offsite_courses_dicts = self.connection.execute(sql_query)\
            .mappings().all()
        return offsite_courses_dicts

    def get_topics(self, id_program):
        sql_query = text(
            f"SELECT description FROM topics "
            f"WHERE id_program = {id_program}")
        topics = self.connection.execute(sql_query).fetchall()
        return list(topic[0] for topic in topics)

    def get_programs(self):
        sql_query = text("SELECT name FROM programs")
        programs = self.connection.execute(sql_query).fetchall()
        return list(program[0] for program in programs)

    def get_teachers(self):
        sql_query = text("SELECT name, surname FROM teachers")
        teachers = self.connection.execute(sql_query).fetchall()
        return list(teacher[0] + " " + teacher[1] for teacher in teachers)

    def get_teacher_name_by_id(self, id_teacher):
        sql_query = text(
            f"SELECT name FROM teachers WHERE id_teacher = {id_teacher}")
        teacher_name = self.connection.execute(sql_query).fetchone()
        return teacher_name[0]

    def get_teacher_surname_by_id(self, id_teacher):
        sql_query = text(
            f"SELECT surname FROM teachers WHERE id_teacher = {id_teacher}")
        teacher_name = self.connection.execute(sql_query).fetchone()
        return teacher_name[0]

    def get_program_by_id(self, id_program):
        sql_query = text(
            f"SELECT name FROM programs WHERE id_program = {id_program}")
        teacher_name = self.connection.execute(sql_query).fetchone()
        return teacher_name[0]

    def get_local_courses_str(self):
        local_courses_dicts = self.get_local_courses_dict()
        s = ""
        for course_dict in local_courses_dicts:
            s += f"\nName: {course_dict['name']}\n" \
                 "Teacher: " \
                 f"{self.get_teacher_name_by_id(course_dict['id_teacher'])} "\
                 f"{self.get_teacher_surname_by_id(course_dict['id_teacher'])}\n"\
                 f"Block: {course_dict['block']}\n" \
                 f"Audience number: {course_dict['audience_number']}\n" \
                 "Program: " \
                 f"{self.get_program_by_id(course_dict['id_program'])}\n"
        return s

    def get_offsite_courses_str(self):
        offsite_courses_dicts = self.get_offsite_courses_dict()
        s = ""
        for course_dict in offsite_courses_dicts:
            s += f"\nName: {course_dict['name']}\n" \
                 "Teacher: " \
                 f"{self.get_teacher_name_by_id(course_dict['id_teacher'])} "\
                 f"{self.get_teacher_surname_by_id(course_dict['id_teacher'])}\n"\
                 f"Address: {course_dict['address']}\n" \
                 "Program: " \
                 f"{self.get_program_by_id(course_dict['id_program'])}\n"
        return s

    def get_teachers_courses(self, id_teacher):
        courses = []
        local_courses_dicts = self.get_local_courses_dict()
        offsite_courses_dicts = self.get_offsite_courses_dict()

        for course in local_courses_dicts:
            if course["id_teacher"] == id_teacher:
                courses.append(LocalCourse(
                    course["name"], course["block"],
                    course["audience_number"],
                    *software_academy.get_topics(course["id_program"])
                    )
                )

        for course in offsite_courses_dicts:
            if course["id_teacher"] == id_teacher:
                courses.append(LocalCourse(
                    course["name"], course["address"],
                    *software_academy.get_topics(course["id_program"])
                    )
                )

        return courses

    def add_local_course(self, local_course, id_program, id_teacher):
        if not isinstance(local_course, LocalCourse):
            raise TypeError("expected LocalCourse type")
        sql_query = text(
            f"INSERT local_courses(name, id_teacher, block, audience_number, "
            f"id_program) "
            "VALUES "
            f"('{local_course.name}', {id_teacher}, "
            f"{local_course.block}, {local_course.audience_number}, "
            f"{id_program})")
        self.connection.execute(sql_query)

    def add_offsite_course(self, offsite_course, id_program, id_teacher):
        if not isinstance(offsite_course, OffsiteCourse):
            raise TypeError("expected OffsiteCourse type")
        sql_query = text(
            f"INSERT offsite_courses(name, id_teacher, address, "
            f"id_program) "
            "VALUES "
            f"('{offsite_course.name}', {id_teacher}, "
            f"'{offsite_course.address}', "
            f"{id_program})")
        self.connection.execute(sql_query)

    def add_teacher(self, name, surname):
        if not isinstance(name, str):
            raise TypeError("the name must be a string")
        if not isinstance(surname, str):
            raise TypeError("the surname must be a string")
        sql_query = text(
            f"INSERT teachers(name, surname) "
            "VALUES "
            f"('{name}', '{surname}')")
        self.connection.execute(sql_query)


software_academy = SoftwareAcademy()
