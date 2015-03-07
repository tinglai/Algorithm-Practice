create table PageUrl(
pageID int NOT NULL,
pageTitle varchar(255),
pageUrl varchar(255),
primary key(pageID)
);

create table Category(
pageID int NOT NULL,
category varchar(255),
primary key(pageID, category),
foreign key(pageID) references PageUrl(PageID)
);

create table Image(
pageID int NOT NULL,
image varchar(255),
primary key(pageID),
foreign key(pageID) references PageUrl(PageID)
);

create table InfoBox(
pageID int NOT NULL,
info text,

foreign key(pageID) references PageUrl(PageID)
);
