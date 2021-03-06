Notes about the FS Scenery Library Database Schema
----------------------------------------------------------

----------------------------------------------------------
SQL scripts that create the database schema:

* atools/resources/sql/fs/db/create_ap_schema.sql:
  Airports, runways, COM, approaches, transitions and other airport related tables.

* atools/resources/sql/fs/db/create_boundary_schema.sql:
  Airspace boundaries and related frequencies

* atools/resources/sql/fs/db/create_meta_schema.sql:
  Metadata for BGL files and scenery areas.

* atools/resources/sql/fs/db/create_nav_schema.sql:
  VOR, NDB, ILS, waypoints and airways.

* atools/resources/sql/fs/db/create_route_schema.sql:
  Tables needed to route calculation.

----------------------------------------------------------
General Notes:

* Boolean columns have prefixes like "has_" or "is_" and contain 0 or 1 values but are not nullable

* Frequencies are scaled up to integer values: MHz * 1000 for COM, VOR, ILS and kHz * 100 for NDB frequencies

* Each table has its own id range. So ids between different tables can overlap. Ids are always > 0.

* Altitude and runway dimensions are in feet and radio navaid ranges are in NM.
  See separate comments for the table columns for used units.

* Headings are degree true.

* Types are stored as strings and can be looked up as enumerations in the C++ code.

* Foreign keys are tested and are usually valid but not enabled per default during
  loading in Little Navmap (for performance reasons)

* Tables are partially denormalized for performance reasons

* See the following links for more information about the FS scenery database and BGL files:
  http://www.fsdeveloper.com/wiki/index.php?title=BGL_File_Format
  https://msdn.microsoft.com/en-us/library/cc526978.aspx
