/*****************************************************************************
* Copyright 2015-2016 Alexander Barthel albar965@mailbox.org
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#ifndef WRITER_WRITERBASEBASIC_H_
#define WRITER_WRITERBASEBASIC_H_

#include "sql/sqlquery.h"

namespace atools {
namespace sql {
class SqlDatabase;
}

namespace fs {
class BglReaderOptions;
namespace writer {
class RunwayIndex;
class AirportIndex;
class DataWriter;

class WriterBaseBasic
{
public:
  WriterBaseBasic(atools::sql::SqlDatabase& sqlDb,
                  atools::fs::writer::DataWriter& writer,
                  const QString& tablename,
                  const QString& sqlParam);

  virtual ~WriterBaseBasic();

protected:
  atools::fs::writer::DataWriter& getDataWriter()
  {
    return dataWriter;
  }

  const atools::fs::BglReaderOptions& getOptions();

  atools::fs::writer::RunwayIndex *getRunwayIndex();

  atools::fs::writer::AirportIndex *getAirportIndex();

  atools::sql::SqlQuery& getStmt()
  {
    return stmt;
  }

  void bind(const QString& placeholder, const QVariant& val)
  {
    return stmt.bindValue(placeholder, val);
  }

  void executeStatement();
  void clearStatement();

private:
  atools::sql::SqlQuery stmt;
  QString sql, tablename;
  atools::sql::SqlDatabase& db;
  atools::fs::writer::DataWriter& dataWriter;

};

} // namespace writer
} // namespace fs
} // namespace atools

#endif /* WRITER_WRITERBASEBASIC_H_ */